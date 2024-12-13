#include "../include/dfs.hpp"

bool dfs(vector<vector<char>> &grid, string word, int grid_size, int pointer, int row, int col, vector<vector<bool>> &visited)
{
    // base
    if (pointer == word.size())
    {
        return true;
    };

    int directions[8][2] = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

    for (int i = 0; i < 8; i++)
    {
        int new_row = row + directions[i][0];
        int new_col = col + directions[i][1];

        if (0 <= new_row && new_row < grid_size && 0 <= new_col && new_col < grid_size &&
            !visited[new_row][new_col] && grid[new_row][new_col] == word[pointer])
        {
            visited[new_row][new_col] = true;

            // Recurse to the next character
            if (dfs(grid, word, grid_size, pointer + 1, new_row, new_col, visited))
            {
                return true;
            }

            // Backtrack
            visited[new_row][new_col] = false;
        }
    }

    return false;
}

int dfswrapper(vector<vector<char>> grid, string word, int score, int grid_size, set<string> &visited)
{
    // Edge case: empty word
    if (word.empty())
    {
        cout << "No input. Try again.\n";
        return score;
    }

    // edge case: if word already visited
    if (visited.find(word) != visited.end())
    {
        cout << "Word already found! Try another word. ";
        return score;
    };

    for (int r = 0; r < grid_size; ++r)
    {
        for (int c = 0; c < grid_size; ++c)
        {
            char value = grid[r][c];

            // if the first letter in word is equal to value:
            if (value == word[0])
            {
                vector<vector<bool>> visited_cell(grid_size, vector<bool>(grid_size, false));
                visited_cell[r][c] = true;

                if (dfs(grid, word, grid_size, 1, r, c, visited_cell))
                {
                    cout << "Valid Word!\n";
                    visited.insert(word);
                    return score + (word.length() * 9);
                }
            }
        }
    }
    // return score
    cout << "Invalid Word! Try Again \n";
    return score;
}
