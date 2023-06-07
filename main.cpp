#include <dict.hpp>
#include <util.hpp>

using namespace NFreq;

int main(int argc, const char* argv[]) {
    TCliArgs cli {argc, argv};
    std::string content = ReadContent(cli.InputFile);
    TNonOwningFrequencyDict dict {&content};
    dict.PrettyPrint(cli.OutputFile);
    return 0;
}
