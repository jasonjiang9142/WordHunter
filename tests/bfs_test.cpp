#include "gtest/gtest.h"
#include "../include/bfs.hpp"
#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <functional>

// Helper function to capture output in tests
std::string capture_output(std::function<void()> func)
{
    std::ostringstream os;
    std::streambuf *old_buf = std::cout.rdbuf();
    std::cout.rdbuf(os.rdbuf());
    func();
    std::cout.rdbuf(old_buf);
    return os.str();
}

// Test case for bfs function
TEST(BfsTest, TestBfsWordFound)
{
    std::vector<std::vector<char>> grid = {
        {'t', 'h', 'a', 'r'},
        {'h', 'e', 'i', 's'},
        {'a', 'n', 't', 'r'},
        {'r', 's', 't', 'h'}};

    std::vector<std::vector<bool>> visited(4, std::vector<bool>(4, false));

    // Test for a word that exists
    bool result = bfs(grid, "hen", 4, 0, 0, visited);
    EXPECT_TRUE(result);
}

TEST(BfsTest, TestBfsWordNotFound)
{
    std::vector<std::vector<char>> grid = {
        {'t', 'h', 'a', 'r'},
        {'h', 'e', 'i', 's'},
        {'a', 'n', 't', 'r'},
        {'r', 's', 't', 'h'}};

    std::vector<std::vector<bool>> visited(4, std::vector<bool>(4, false));

    // Test for a word that does not exist
    bool result = bfs(grid, "hello", 4, 0, 0, visited);
    EXPECT_FALSE(result);
}

// Test case for bfswrapper function
TEST(BfsWrapperTest, TestBfsWrapperValidWord)
{
    std::vector<std::vector<char>> grid = {
        {'t', 'h', 'a', 'r'},
        {'h', 'e', 'i', 's'},
        {'a', 'n', 't', 'r'},
        {'r', 's', 't', 'h'}};
    std::set<std::string> visited_words;
    int score = 0;

    // Test for a valid word
    int new_score = bfswrapper(grid, "sit", score, 4, visited_words);
    EXPECT_EQ(new_score, score + 27);            // 3 letters * 9 points
    EXPECT_TRUE(visited_words.count("sit") > 0); // Word should be added to visited
}

TEST(BfsWrapperTest, TestBfsWrapperInvalidWord)
{
    std::vector<std::vector<char>> grid = {
        {'t', 'h', 'a', 'r'},
        {'h', 'e', 'i', 's'},
        {'a', 'n', 't', 'r'},
        {'r', 's', 't', 'h'}};
    std::set<std::string> visited_words;
    int score = 0;

    // Test for an invalid word
    int new_score = bfswrapper(grid, "hello", score, 4, visited_words);
    EXPECT_EQ(new_score, score);                    // Score should not change
    EXPECT_TRUE(visited_words.count("hello") == 0); // Word should not be added to visited
}

TEST(BfsWrapperTest, TestBfsWrapperEmptyWord)
{
    std::vector<std::vector<char>> grid = {
        {'t', 'h', 'a', 'r'},
        {'h', 'e', 'i', 's'},
        {'a', 'n', 't', 'r'},
        {'r', 's', 't', 'h'}};
    std::set<std::string> visited_words;
    int score = 0;

    // Test for an empty word
    int new_score = bfswrapper(grid, "", score, 4, visited_words);
    EXPECT_EQ(new_score, score);        // Score should not change
    EXPECT_TRUE(visited_words.empty()); // No words should be added to visited
}

TEST(BfsWrapperTest, TestBfsWrapperWordAlreadyFound)
{
    std::vector<std::vector<char>> grid = {
        {'t', 'h', 'a', 'r'},
        {'h', 'e', 'i', 's'},
        {'a', 'n', 't', 'r'},
        {'r', 's', 't', 'h'}};
    std::set<std::string> visited_words;
    visited_words.insert("test");
    int score = 0;

    // Test for a word that has already been found
    int new_score = bfswrapper(grid, "test", score, 4, visited_words);
    EXPECT_EQ(new_score, score);                  // Score should not change
    EXPECT_TRUE(visited_words.count("test") > 0); // Word should already be in visited
}

// Test when grid is empty
TEST(BfsTest, TestBfsEmptyGrid)
{
    std::vector<std::vector<char>> grid;
    std::vector<std::vector<bool>> visited(0, std::vector<bool>(0, false));

    bool result = bfs(grid, "test", 0, 0, 0, visited);
    EXPECT_FALSE(result); // No word can be found in an empty grid
}

// Test with a grid of size 1x1
TEST(BfsTest, TestBfsSingleCellGrid)
{
    std::vector<std::vector<char>> grid = {{'t'}};
    std::vector<std::vector<bool>> visited(1, std::vector<bool>(1, false));

    // Test for a word that exists
    bool result = bfs(grid, "t", 1, 0, 0, visited);
    EXPECT_TRUE(result); // "t" should be found in the grid

    // Test for a word that does not exist
    result = bfs(grid, "test", 1, 0, 0, visited);
    EXPECT_FALSE(result); // "test" cannot fit in a 1x1 grid
}

// Test with a grid where all cells are the same
TEST(BfsTest, TestBfsSameLetterGrid)
{
    std::vector<std::vector<char>> grid = {
        {'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a'}};
    std::vector<std::vector<bool>> visited(4, std::vector<bool>(4, false));

    // Test for a word that exists
    bool result = bfs(grid, "aaa", 4, 0, 0, visited);
    EXPECT_TRUE(result); // "aaa" should be found in the grid

    // Test for a word that does not exist
    result = bfs(grid, "abc", 4, 0, 0, visited);
    EXPECT_FALSE(result); // "abc" cannot be formed from 'a' only
}
