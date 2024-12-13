#include "../include/bfs.hpp"
bool bfs(std::vector<std::vector<char>> &grid, std::string word, int grid_size, int row, int col, std::vector<std::vector<bool>> &visited)
{
    // no size grid
    if (grid_size == 0)
    {
        return false;
    }
    int directions[8][2] = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

    std::queue<std::pair<std::pair<int, int>, int>> q;
    q.push({{row, col}, 0});
    visited[row][col] = true;

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();

        int cur_row = current.first.first;
        int cur_col = current.first.second;
        int pointer = current.second;

        // Check if we have matched all letters in the word
        if (pointer == word.size() - 1)
        {
            return true;
        }

        // Try all 8 directions
        for (int i = 0; i < 8; i++)
        {
            int new_row = cur_row + directions[i][0];
            int new_col = cur_col + directions[i][1];

            // Ensure the new position is within bounds and has not been visited
            if (0 <= new_row && new_row < grid_size && 0 <= new_col && new_col < grid_size &&
                !visited[new_row][new_col] && grid[new_row][new_col] == word[pointer + 1]) // Fix here
            {
                q.push({{new_row, new_col}, pointer + 1});
                visited[new_row][new_col] = true; // Mark the new cell as visited
            }
        }
    }

    return false;
}

int bfswrapper(std::vector<std::vector<char>> grid, std::string word, int score, int grid_size, std::set<std::string> &visited)
{
    // Edge case: empty word
    if (word.empty())
    {
        std::cout << "No input. Try again.\n";
        return score;
    }

    // Edge case: if word already visited
    if (visited.find(word) != visited.end())
    {
        std::cout << "Word already found! Try another word. ";
        return score;
    }

    // Iterate over the grid to find the first character of the word
    for (int r = 0; r < grid_size; ++r)
    {
        for (int c = 0; c < grid_size; ++c)
        {
            if (grid[r][c] == word[0]) // First letter matches
            {
                // Create a visited grid for BFS traversal
                std::vector<std::vector<bool>> visited_cell(grid_size, std::vector<bool>(grid_size, false));

                if (bfs(grid, word, grid_size, r, c, visited_cell))
                {
                    std::cout << "Valid Word!\n";
                    visited.insert(word);               // Add word to visited set
                    return score + (word.length() * 9); // Update score (word length * 9)
                }
            }
        }
    }

    std::cout << "Invalid Word! Try Again\n";
    return score; // If word isn't found, return the original score
}
