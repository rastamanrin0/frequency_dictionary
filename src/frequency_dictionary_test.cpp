#include <gtest/gtest.h>

#include "../src/frequency_dictionary.hpp"

namespace frequency_dictionary {

namespace {
TEST(FrequencyDictionaryTest, GetFrequencyDictionaryResultShouldReturnWordsSortedByCountAndLexicographical) {
  const std::vector<std::pair<std::string, size_t>> expected_frequency_dictionary = {
    {"is", 1},
    {"passed", 1},
    {"test", 1}
  };

  std::string text = "TEST Is 31239023091 pasSeD";

  auto frequency_dictionary = FrequencyDictionary(std::move(text));
  const auto result = frequency_dictionary.GetFrequencyDictionaryResult();

  ASSERT_EQ(expected_frequency_dictionary, result);
}

TEST(FrequencyDictionaryTest, UpdateTextToLowerCaseShouldUpdateAllLetterToLowerCaseAndUpdateOtherSymbolsToSpace) {
  const std::string expected_string = "test for                  string";
  std::string text = "TEST for]]@   31239023091 StRinG";

  auto frequency_dictionary = FrequencyDictionary(std::move(text));
  frequency_dictionary.UpdateTextToLowerCase();

  ASSERT_EQ(expected_string, frequency_dictionary.GetText());
}
} // namespace

} // namespace frequency_dictionary

// Точка входа в тестовое приложение
int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::FLAGS_gtest_color = "yes";
  ::testing::FLAGS_gtest_repeat = 1;

  return RUN_ALL_TESTS();
}