#include <fstream>

#include "frequency_dictionary.hpp"

void ValidateCountOfFiles(const int argc)
{
    switch (argc)
    {
    case 1:
        throw std::runtime_error("Input and output is required, please add them.");
    case 2:
        throw std::runtime_error("Output is required, please add it.");
    }
}

int main(int argc, char *argv[])
{
    ValidateCountOfFiles(argc);

    std::ifstream input(argv[1]);
    std::ofstream output(argv[2]);

    std::string text;

    text.assign((std::istreambuf_iterator<char>(input.rdbuf())), std::istreambuf_iterator<char>());

    auto frequency_dictionary = frequency_dictionary::FrequencyDictionary(std::move(text));
    const auto frequency_dictionary_for_output = frequency_dictionary.GetFrequencyDictionaryResult();

    for (const auto& count_of_word : frequency_dictionary_for_output) {
        output << count_of_word.second <<  ' ' << count_of_word.first;
        output << '\n';
    }

    return 0;
}