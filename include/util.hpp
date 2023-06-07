#pragma once

#include <filesystem>

namespace NFreq {

    struct TCliArgs {
        std::filesystem::path InputFile;
        std::filesystem::path OutputFile;

        TCliArgs(int argc, const char* argv[]) noexcept;
    };

    std::string ReadContent(const std::filesystem::path& path) noexcept;

} // namespace NFreq
