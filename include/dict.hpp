#pragma once

#include <unordered_map>
#include <string_view>
#include <filesystem>

namespace NFreq {

    class TNonOwningFrequencyDict {
    public:
        TNonOwningFrequencyDict(std::string* ss) noexcept;

        void PrettyPrint(const std::filesystem::path& file) const noexcept;

    private:
        std::unordered_map<std::string_view, size_t> Frequencies_;
    };

} // namespace NFreq
