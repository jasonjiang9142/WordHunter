#include "../include/bfs.hpp"

//------

bool bfs(vector<vector<char>> &grid, string word, int grid_size, int row, int col, vector<vector<bool>> &visited)
{
    int directions[8][2] = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

    queue<pair<pair<int, int>, int>> q;
    q.push({{row, col}, 1});
    visited[row][col] = true;

    while (!q.empty())
    {
        // pop the queue
        auto current = q.front();
        q.pop();

        int cur_row = current.first.first;
        int cur_col = current.first.second;
        int pointer = current.second;

        // return case
        if (pointer == word.size())
        {
            return true;
        }

        for (int i = 0; i < 8; i++)
        {
            int new_row = row + directions[i][0];
            int new_col = col + directions[i][1];

            if (0 <= new_row && new_row < grid_size && 0 <= new_col && new_col < grid_size &&
                !visited[new_row][new_col] && grid[new_row][new_col] == word[pointer])
            {
                q.push({{new_row, new_col}, pointer + 1});
                visited[new_row][new_col] = true;
            }
        }
    }

    return false;
}

int bfswrapper(vector<vector<char>> grid, string word, int score, int grid_size, set<string> &visited)
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

                if (bfs(grid, word, grid_size, r, c, visited_cell))
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
