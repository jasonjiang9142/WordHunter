#include <gtest/gtest.h>
#include <vector>
#include <set>
#include <string>
#include "../include/dfs.hpp"

using namespace std;

TEST(DFSWrappersTest, TestValidWord)
{
    vector<vector<char>> grid = {
        {'t', 'h', 'a', 'r'},
        {'h', 'e', 'i', 's'},
        {'a', 'n', 't', 'r'},
        {'r', 's', 't', 'h'}};
    set<string> visited_words;
    int score = 0;

    // Test for a valid word
    int new_score = dfswrapper(grid, "sit", score, 4, visited_words);
    EXPECT_EQ(new_score, score + 27);            // 3 letters * 9 points
    EXPECT_TRUE(visited_words.count("sit") > 0); // Word should be added to visited
}

TEST(DFSWrappersTest, TestWordAlreadyFound)
{
    vector<vector<char>> grid = {
        {'t', 'h', 'a', 'r'},
        {'h', 'e', 'i', 's'},
        {'a', 'n', 't', 'r'},
        {'r', 's', 't', 'h'}};
    set<string> visited_words = {"sit"};
    int score = 0;

    // Test for a word that has already been found
    int new_score = dfswrapper(grid, "sit", score, 4, visited_words);
    EXPECT_EQ(new_score, score);                 // Score should not change
    EXPECT_TRUE(visited_words.count("sit") > 0); // Word should still be in visited
}

TEST(DFSWrappersTest, TestEmptyWord)
{
    vector<vector<char>> grid = {
        {'t', 'h', 'a', 'r'},
        {'h', 'e', 'i', 's'},
        {'a', 'n', 't', 'r'},
        {'r', 's', 't', 'h'}};
    set<string> visited_words;
    int score = 0;

    // Test for an empty word
    int new_score = dfswrapper(grid, "", score, 4, visited_words);
    EXPECT_EQ(new_score, score);        // Score should not change
    EXPECT_TRUE(visited_words.empty()); // Visited words should remain empty
}

TEST(DFSWrappersTest, TestInvalidWord)
{
    vector<vector<char>> grid = {
        {'t', 'h', 'a', 'r'},
        {'h', 'e', 'i', 's'},
        {'a', 'n', 't', 'r'},
        {'r', 's', 't', 'h'}};
    set<string> visited_words;
    int score = 0;

    // Test for an invalid word
    int new_score = dfswrapper(grid, "xyz", score, 4, visited_words);
    EXPECT_EQ(new_score, score);        // Score should remain the same
    EXPECT_TRUE(visited_words.empty()); // Visited words should remain empty
}

TEST(DFSWrappersTest, TestMultipleWords)
{
    vector<vector<char>> grid = {
        {'t', 'h', 'a', 'r'},
        {'h', 'e', 'i', 's'},
        {'a', 'n', 't', 'r'},
        {'r', 's', 't', 'h'}};
    set<string> visited_words;
    int score = 0;

    // Test for multiple valid words
    score = dfswrapper(grid, "sit", score, 4, visited_words); // score should increase
    EXPECT_EQ(score, 27);                                     // 3 letters * 9 points
    EXPECT_TRUE(visited_words.count("sit") > 0);              // Word should be added to visited

    score = dfswrapper(grid, "is", score, 4, visited_words); // score should increase again
    EXPECT_EQ(score, 45);                                    // 2 letters * 9 points

    score = dfswrapper(grid, "sit", score, 4, visited_words); // "sit" should not be added again
    EXPECT_EQ(score, 45);                                     // Score should remain the same
    EXPECT_TRUE(visited_words.count("sit") > 0);              // "sit" should already be in visited
}

TEST(DFSWrappersTest, TestWordTooLong)
{
    vector<vector<char>> grid = {
        {'t', 'h', 'a', 'r'},
        {'h', 'e', 'i', 's'},
        {'a', 'n', 't', 'r'},
        {'r', 's', 't', 'h'}};
    set<string> visited_words;
    int score = 0;

    // Test for a word longer than the grid dimensions allow
    int new_score = dfswrapper(grid, "thisisaninvalidword", score, 4, visited_words);
    EXPECT_EQ(new_score, score);        // Score should remain the same
    EXPECT_TRUE(visited_words.empty()); // Visited words should remain empty
}

TEST(DFSWrappersTest, TestSingleLetterWord)
{
    vector<vector<char>> grid = {
        {'t', 'h', 'a', 'r'},
        {'h', 'e', 'i', 's'},
        {'a', 'n', 't', 'r'},
        {'r', 's', 't', 'h'}};
    set<string> visited_words;
    int score = 0;

    // Test for a single-letter word
    int new_score = dfswrapper(grid, "h", score, 4, visited_words);
    EXPECT_EQ(new_score, score + 9);           // Single letter * 9 points
    EXPECT_TRUE(visited_words.count("h") > 0); // Word should be added to visited
}

TEST(DFSWrappersTest, TestWordNotOnGrid)
{
    vector<vector<char>> grid = {
        {'t', 'h', 'a', 'r'},
        {'h', 'e', 'i', 's'},
        {'a', 'n', 't', 'r'},
        {'r', 's', 't', 'h'}};
    set<string> visited_words;
    int score = 0;

    // Test for a word that cannot be formed from the grid
    int new_score = dfswrapper(grid, "hello", score, 4, visited_words);
    EXPECT_EQ(new_score, score);        // Score should remain the same
    EXPECT_TRUE(visited_words.empty()); // Visited words should remain empty
}

TEST(DFSWrappersTest, TestRepeatedLetters)
{
    vector<vector<char>> grid = {
        {'a', 'b', 'c', 'd'},
        {'e', 'f', 'g', 'h'},
        {'i', 'j', 'k', 'l'},
        {'m', 'n', 'o', 'p'}};
    set<string> visited_words;
    int score = 0;

    // Test for a word that requires using the same letter twice
    int new_score = dfswrapper(grid, "ee", score, 4, visited_words);
    EXPECT_EQ(new_score, score);        // Score should not change
    EXPECT_TRUE(visited_words.empty()); // Visited words should remain empty
}

TEST(DFSWrappersTest, TestGridWithDuplicates)
{
    vector<vector<char>> grid = {
        {'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a'}};
    set<string> visited_words;
    int score = 0;

    // Test for a word in a grid with duplicate letters
    int new_score = dfswrapper(grid, "aaa", score, 4, visited_words);
    EXPECT_EQ(new_score, score + 27);            // 3 letters * 9 points
    EXPECT_TRUE(visited_words.count("aaa") > 0); // Word should be added to visited
}

TEST(DFSWrappersTest, TestDifferentGridSize)
{
    vector<vector<char>> grid = {
        {'a', 'b'},
        {'c', 'd'}};
    set<string> visited_words;
    int score = 0;

    // Test for a word in a smaller grid
    int new_score = dfswrapper(grid, "ab", score, 2, visited_words);
    EXPECT_EQ(new_score, score + 18);           // 2 letters * 9 points
    EXPECT_TRUE(visited_words.count("ab") > 0); // Word should be added to visited
}

TEST(DFSWrappersTest, TestDiagonalWord)
{
    vector<vector<char>> grid = {
        {'a', 'b', 'c', 'd'},
        {'e', 'f', 'g', 'h'},
        {'i', 'j', 'k', 'l'},
        {'m', 'n', 'o', 'p'}};
    set<string> visited_words;
    int score = 0;

    // Test for a word formed diagonally
    int new_score = dfswrapper(grid, "afkp", score, 4, visited_words);
    EXPECT_EQ(new_score, score + 36);             // 4 letters * 9 points
    EXPECT_TRUE(visited_words.count("afkp") > 0); // Word should be added to visited
}
