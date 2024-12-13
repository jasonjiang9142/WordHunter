#include <gtest/gtest.h>
#include <fstream>
#include <set>
#include <string>
#include "../include/dictionary.hpp" // Adjust the include path to your header

// Test fixture for dictionary loading
class DictionaryTest : public ::testing::Test
{
protected:
    // Helper function to create a temporary file with given words
    void createTestFile(const std::string &filename, const std::vector<std::string> &words)
    {
        std::ofstream file(filename);
        for (const auto &word : words)
        {
            file << word << std::endl;
        }
    }

    // Helper function to remove a test file
    void removeTestFile(const std::string &filename)
    {
        std::remove(filename.c_str());
    }
};

// Test case: Check if dictionary loads words correctly from a valid file
TEST_F(DictionaryTest, LoadDictionaryValidFile)
{
    std::string filename = "test_dict.txt";
    std::vector<std::string> words = {"apple", "banana", "cherry"};

    // Create a temporary test file with words
    createTestFile(filename, words);

    // Load the dictionary
    set<string> dictionary = loadDictionary(filename);

    // Verify the dictionary contains the correct words
    EXPECT_EQ(dictionary.size(), words.size());
    for (const auto &word : words)
    {
        EXPECT_TRUE(dictionary.find(word) != dictionary.end());
    }

    // Clean up the test file
    removeTestFile(filename);
}

// Test case: Check if dictionary returns an empty set for a non-existent file
TEST_F(DictionaryTest, LoadDictionaryFileNotFound)
{
    std::string filename = "non_existent_file.txt";

    // Try to load a non-existent file
    set<string> dictionary = loadDictionary(filename);

    // Ensure the dictionary is empty since the file doesn't exist
    EXPECT_TRUE(dictionary.empty());
}

// Test case: Check if dictionary is empty when the file is empty
TEST_F(DictionaryTest, LoadDictionaryEmptyFile)
{
    std::string filename = "empty_dict.txt";

    // Create an empty file
    createTestFile(filename, {});

    // Load the dictionary from the empty file
    set<string> dictionary = loadDictionary(filename);

    // Verify that the dictionary is empty
    EXPECT_TRUE(dictionary.empty());

    // Clean up the test file
    removeTestFile(filename);
}

// Test case: Ensure the dictionary is case-insensitive (all words should be lowercase)
TEST_F(DictionaryTest, LoadDictionaryCaseInsensitivity)
{
    std::string filename = "case_sensitive_dict.txt";
    std::vector<std::string> words = {"Apple", "banana", "CHERRY"};

    // Create a temporary test file with mixed-case words
    createTestFile(filename, words);

    // Load the dictionary
    set<string> dictionary = loadDictionary(filename);

    // Verify that all words are stored in lowercase in the dictionary
    EXPECT_EQ(dictionary.size(), words.size());
    EXPECT_TRUE(dictionary.find("apple") != dictionary.end());
    EXPECT_TRUE(dictionary.find("banana") != dictionary.end());
    EXPECT_TRUE(dictionary.find("cherry") != dictionary.end());

    // Clean up the test file
    removeTestFile(filename);
}
