#include "frequency_dictionary.hpp"

#include <map>
#include <sstream>
#include <algorithm>

namespace frequency_dictionary {

namespace {

const char kSpace = ' ';

struct PairComparison {
    bool operator()(const std::pair<std::string, size_t>& first_pair, const std::pair<std::string, size_t>& second_pair) {
        return first_pair.second > second_pair.second;
    }
};

struct ToLowerCase {
	void operator()(char& element_of_string)
	{
		if (std::isalpha(element_of_string)) {
            element_of_string = std::tolower(element_of_string);
        }
        else {
            element_of_string = kSpace;
        }
	}
};

} // namespace

void FrequencyDictionary::UpdateTextToLowerCase() {
    std::for_each(text_.begin(), text_.end(), ToLowerCase());
}

std::vector<std::pair<std::string, size_t>> FrequencyDictionary::GetFrequencyDictionaryResult() {
    std::vector<std::pair<std::string, size_t>> result;

    UpdateTextToLowerCase();

    std::map<std::string, size_t> count_of_words;

    std::stringstream text_to_stream(text_);

    std::string word;
    while (text_to_stream >> word) {
        count_of_words[word]++;
    }

    result.reserve(count_of_words.size());
    for (const auto& word : count_of_words) {
        result.push_back(word);
    }

    std::stable_sort(result.begin(), result.end(), PairComparison());
    return result;
}

} // namespace frequency_dictonary