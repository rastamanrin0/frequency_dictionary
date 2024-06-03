cmake_minimum_required(VERSION 3.2)
project(FrequencyDictionary)

if ("${TARGET_CPU}" STREQUAL "amd64")
    set (CMAKE_SIZEOF_VOID_P 8)

    set_property (GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS TRUE)
    set_property (GLOBAL PROPERTY FIND_LIBRARY_USE_LIB32_PATHS FALSE)
elseif ("${TARGET_CPU}" STREQUAL "x86")
    set (CMAKE_SIZEOF_VOID_P 4)

    set_property (GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS FALSE)
    set_property (GLOBAL PROPERTY FIND_LIBRARY_USE_LIB32_PATHS TRUE)

    if (GCC)
        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
        set (CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -m32")
    endif ()
else ()
    message (FATAL_ERROR "Unsupported CPU: ${TARGET_CPU}")
endif ()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

add_executable(frequency_dictionary_app main.cpp frequency_dictionary.hpp frequency_dictionary.cpp)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(frequency_dictionary_test frequency_dictionary_test.cpp frequency_dictionary.hpp frequency_dictionary.cpp)
target_link_libraries(frequency_dictionary_test ${GTEST_LIBRARIES} pthread)

add_test(NAME FrequencyDictionaryTest COMMAND frequency_dictionary_test --gtest_color=yes)
