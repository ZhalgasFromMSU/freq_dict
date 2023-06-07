#include <util.hpp>

#include <iostream>
#include <fstream>

namespace NFreq {

    TCliArgs::TCliArgs(int argc, const char* argv[]) noexcept {
        if (argc != 3) {
            std::cerr << "Two params should be specified" << std::endl;
            std::terminate();
        }

        InputFile = argv[1];
        if (!std::filesystem::exists(InputFile)) {
            std::cerr << "Input file doesn't exist" << std::endl;
            std::terminate();
        }

        OutputFile = argv[2];
    }

    std::string ReadContent(const std::filesystem::path& path) noexcept {
    // https://insanecoding.blogspot.com/2011/11/how-to-read-in-file-in-c.html
        std::ifstream in {path};
        if (!in) {
            std::cerr << "Couldn't read from file: " << std::error_code{errno, std::system_category()}.message() << std::endl;
            std::terminate();
        }
        std::ostringstream contents;
        contents << in.rdbuf();
        return std::move(contents).str();
    }
} // namespace NFreq
