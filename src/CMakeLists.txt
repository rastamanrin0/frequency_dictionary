cmake_minimum_required(VERSION 3.2)
project(FrequencyDictionary)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

add_executable(frequency_dictionary_app main.cpp frequency_dictionary.hpp frequency_dictionary.cpp)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(frequency_dictionary_test frequency_dictionary_test.cpp frequency_dictionary.hpp frequency_dictionary.cpp)
target_link_libraries(frequency_dictionary_test ${GTEST_LIBRARIES} pthread)

add_test(NAME FrequencyDictionaryTest COMMAND frequency_dictionary_test --gtest_color=yes)
