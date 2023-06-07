#include <dict.hpp>

#include <string>
#include <cctype>
#include <string_view>
#include <vector>
#include <compare>
#include <fstream>

namespace NFreq {

    namespace {
        std::string_view NextTokenAndToLower(char** c) {
            while (**c != '\0' && !std::isalpha(**c)) {
                ++(*c);
            }
            const char* viewBegin;
            if (**c == '\0') [[unlikely]] {
                return std::string_view{};
            } else {
                viewBegin = *c;
            }

            while (**c != '\0' && std::isalpha(**c)) {
                **c = std::tolower(**c);
                ++(*c);
            }
            return std::string_view{viewBegin, *c};
        }
    } // namespace

    TNonOwningFrequencyDict::TNonOwningFrequencyDict(std::string* s) noexcept {
        Frequencies_.reserve(s->size()); // because why not
        char* c = s->data();
        std::string_view token = NextTokenAndToLower(&c);
        while (token.size()) {
            Frequencies_[token] += 1;
            token = NextTokenAndToLower(&c);
        }
    }

    void TNonOwningFrequencyDict::PrettyPrint(const std::filesystem::path& file) const noexcept {
        std::vector<std::pair<std::string_view, size_t>> table;
        table.reserve(Frequencies_.size());
        for (const auto& [word, count] : Frequencies_) {
            table.emplace_back(word, count);
        }

        std::sort(
            table.begin(),
            table.end(),
            [](const auto& pair1, const auto& pair2) {
                return pair1.second > pair2.second || pair1.second == pair2.second && pair1.first <=> pair2.first < 0;
            }
        );

        std::ofstream out { file };
        for (const auto& [word, count] : table) {
            out << count << ' ' << word << '\n';
        }
    }

} // namespace NFreq
