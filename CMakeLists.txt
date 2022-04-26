cmake_minimum_required(VERSION 3.21)
project(dictionary_implementation)

set(CMAKE_CXX_STANDARD 14)

add_executable(dictionary_implementation
        main.cpp
        dictionary/UnorderedDictionary.h
        dictionary/Dictionary.h dictionary/utils.h)