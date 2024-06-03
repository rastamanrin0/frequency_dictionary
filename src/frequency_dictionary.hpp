#pragma once

#include <string>
#include <vector>

namespace frequency_dictionary {

class FrequencyDictionary {
public:
    FrequencyDictionary(std::string&& text) : text_(std::move(text)) {}

    std::string GetText() const { return text_; }

    std::vector<std::pair<std::string, size_t>> GetFrequencyDictionaryResult();

    void UpdateTextToLowerCase();

private:
    std::string text_;
};

} // namespace frequency_dictonary
