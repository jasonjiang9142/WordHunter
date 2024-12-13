#include <gtest/gtest.h>
#include "../include/grid.hpp"

const vector<string> bigrams = {"th", "he", "in", "en", "nt", "re", "er", "an", "ti", "es", "on", "at", "se", "nd", "or", "ar", "al", "te", "co", "de", "to", "ra", "et", "ed", "it", "sa", "em", "ro"};
const vector<string> trigrams = {"the", "and", "tha", "ent", "ing", "ion", "tio", "for", "nde", "has", "nce", "edt", "tis", "oft", "sth", "men"};

// Test case: Check if the grid has the correct size
TEST(GridTest, GridSizeTest)
{
    int gridSize = 5; // Size of the grid
    vector<vector<char>> grid = createGrid(gridSize);

    // Check the grid size (gridSize x gridSize)
    EXPECT_EQ(grid.size(), gridSize);    // Check number of rows
    EXPECT_EQ(grid[0].size(), gridSize); // Check number of columns
}

// Test case: Ensure that all letters in the grid are valid lowercase letters
TEST(GridTest, GridContainsValidLetters)
{
    int gridSize = 5; // Size of the grid
    vector<vector<char>> grid = createGrid(gridSize);

    // Ensure all characters are within the valid lowercase letter range
    for (int i = 0; i < gridSize; ++i)
    {
        for (int j = 0; j < gridSize; ++j)
        {
            char letter = grid[i][j];
            EXPECT_TRUE(letter >= 'a' && letter <= 'z') << "Invalid letter at (" << i << ", " << j << ")";
        }
    }
}

// Test case: Ensure that bigrams are placed correctly
TEST(GridTest, BigramsPlacementTest)
{
    int gridSize = 5; // Size of the grid
    vector<vector<char>> grid = createGrid(gridSize);

    // Check if the grid contains at least some bigrams
    bool foundBigram = false;

    for (const auto &bigram : bigrams)
    {
        for (int i = 0; i < gridSize; ++i)
        {
            for (int j = 0; j < gridSize; ++j)
            {
                if (grid[i][j] == bigram[0])
                {
                    // Check the adjacent cell for the second letter of the bigram
                    if (i + 1 < gridSize && grid[i + 1][j] == bigram[1])
                    {
                        foundBigram = true;
                    }
                    else if (j + 1 < gridSize && grid[i][j + 1] == bigram[1])
                    {
                        foundBigram = true;
                    }
                }
            }
        }
    }

    EXPECT_TRUE(foundBigram) << "Bigram not found in the grid.";
}

// Test case: Ensure that trigrams are placed correctly
TEST(GridTest, TrigramsPlacementTest)
{
    int gridSize = 5; // Size of the grid
    vector<vector<char>> grid = createGrid(gridSize);

    // Check if the grid contains at least some trigrams
    bool foundTrigram = false;

    for (const auto &trigram : trigrams)
    {
        for (int i = 0; i < gridSize - 2; ++i)
        { // Ensure there's space for trigram
            for (int j = 0; j < gridSize; ++j)
            {
                if (grid[i][j] == trigram[0])
                {
                    if (i + 1 < gridSize && grid[i + 1][j] == trigram[1] &&
                        i + 2 < gridSize && grid[i + 2][j] == trigram[2])
                    {
                        foundTrigram = true;
                    }
                }
            }
        }
    }

    EXPECT_TRUE(foundTrigram) << "Trigram not found in the grid.";
}

// Test case: Check that the grid generates a non-empty grid
TEST(GridTest, NonEmptyGridTest)
{
    int gridSize = 5; // Size of the grid
    vector<vector<char>> grid = createGrid(gridSize);

    // Check if the grid is not empty
    EXPECT_FALSE(grid.empty()) << "Grid is empty!";
    EXPECT_FALSE(grid[0].empty()) << "Grid rows are empty!";
}

// Test case: Ensure grid size changes with different inputs
TEST(GridTest, DifferentGridSizeTest)
{
    int gridSize = 4; // Size of the grid
    vector<vector<char>> grid = createGrid(gridSize);

    // Check the grid size (gridSize x gridSize)
    EXPECT_EQ(grid.size(), gridSize);    // Check number of rows
    EXPECT_EQ(grid[0].size(), gridSize); // Check number of columns

    gridSize = 6; // Size of the grid
    grid = createGrid(gridSize);

    // Check the grid size (gridSize x gridSize)
    EXPECT_EQ(grid.size(), gridSize);    // Check number of rows
    EXPECT_EQ(grid[0].size(), gridSize); // Check number of columns
}
