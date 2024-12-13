#include <iostream>
#include <chrono>
#include <thread>
#include <set>
#include <string>
#include <algorithm> // For std::transform
#include <cctype>    // For ::tolower
#include "grid.hpp"
#include "dictionary.hpp"

// how to run it: g++ -std=c++11 main.cpp grid.cpp -o main

bool recurse(vector<vector<char>> &grid, string word, int grid_size, int pointer, int row, int col, vector<vector<bool>> &visited)
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
            if (recurse(grid, word, grid_size, pointer + 1, new_row, new_col, visited))
            {
                return true;
            }

            // Backtrack
            visited[new_row][new_col] = false;
        }
    }

    return false;
}

int dfs(vector<vector<char>> grid, string word, int score, int grid_size, set<string> &visited)
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

                if (recurse(grid, word, grid_size, 1, r, c, visited_cell))
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

// initialize gameplay
int main()
{
    // print the rules
    cout << R"( 
=============================================================
!                         _   _                 _            
!                        | | | |               | |           
!  __      _____  _ __ __| | | |__  _   _ _ __ | |_ ___ _ __ 
!  \ \ /\ / / _ \| '__/ _` | | '_ \| | | | '_ \| __/ _ \ '__|
!   \ V  V / (_) | | | (_| | | | | | |_| | | | | ||  __/ |   
!    \_/\_/ \___/|_|  \__,_| |_| |_|\__,_|_| |_|\__\___|_|   
                                                                                                                                                                       
!                                                    by jason
)" << endl;
    cout << R"( 
=============================================================
                        Rules!
=============================================================

    [1] Your goal is to find as many words as possible from the grid of letters.
    [2] Words can be formed by connecting adjacent letters in any direction: 
            [a] horizontally
            [b] vertically
            [c] diagonally

    [3] Words must be at least of size 3 and cannot be reused.
    [4] You can only form words that exist in the dictionary.
    [5] Each word you find earns you points based on its length.
    [6] You will have a limited amount of time to find as many words as possible.

Good luck and enjoy the hunt!

Enter any key to start... 
============================================================
)" << endl;

    // Wait for user input before continuing
    cin.get();

    // Load the dictionary from wordlist.txt
    set<string>
        dictionary = loadDictionary("wordlist.txt");

    while (true)
    {
        int mode;

        // Display a stylish UI with better formatting
        cout << R"( 
=============================================================
                    Welcome to Word Hunt!
=============================================================

Choose between 3 difficulty modes (press CTRL-C to QUIT):
   [1] Easy
   [2] Medium
   [3] Hard

Please enter your choice (1, 2, or 3) : )";

        cin >> mode;

        int grid_size;
        int time_limit;

        // initilize the grid_size and time
        if (mode == 1)
        {
            grid_size = 4;
            time_limit = 60;
        }
        else if (mode == 2)
        {
            grid_size = 5;
            time_limit = 45;
        }
        else if (mode == 3)
        {
            grid_size = 6;
            time_limit = 15;
        }
        else
        {
            cout << "INCORRECT INPUT. TRY AGAIN \n";
            continue;
        }

        vector<vector<char>> grid = createGrid(grid_size);

        // start the game play-> displaying the time remaining, score, and the board

        // intialize our timer
        auto start_time = chrono::high_resolution_clock::now();
        cout << "You have " << time_limit << " seconds to play!\n";

        int current_score = 0;
        set<string> visited;
        vector<string> correct_words;

        while (true)
        {
            // constantly checking the time
            auto now_time = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_time = now_time - start_time;

            // Display grid, current score, and remaining time
            cout << "\nGrid: \n\n";
            printGrid(grid);
            cout << "\nCurrent Score: " << current_score << "\n";

            int time_left = time_limit - int(elapsed_time.count());
            if (time_left <= 0)
            {
                cout << "Time Left: " << 0 << " seconds\n";
            }
            else
            {
                cout << "Time Left: " << time_limit - int(elapsed_time.count()) << " seconds\n";
            }

            // Ask for user input
            string input_word;
            cout << "Enter word: ";
            cin >> input_word;
            transform(input_word.begin(), input_word.end(), input_word.begin(), ::tolower);

            // Check if the word is valid by looking it up in the dictionary
            if (dictionary.find(input_word) == dictionary.end())
            {
                cout << input_word << " is not a valid English word. Try again. \n";
                continue;
            }

            else if (input_word.length() < 3)
            {
                cout << "You need a word of at least length 3. Try again. \n";
                continue;
            }

            int new_score = dfs(grid, input_word, current_score, grid_size, visited);

            // to see if we have new score./main

            if (new_score > current_score)
            {
                correct_words.push_back(input_word);
            }
            current_score = new_score;

            if (elapsed_time.count() >= time_limit)
            {
                cout << R"( 
=============================================================
                      Game Over!
=============================================================

Your total Score was: )"
                     << current_score << R"(
You got )" << correct_words.size()
                     << R"( words correct! 

These are the words you got correct:
-------------------------------------------------------------
)";

                for (const string &word : correct_words)
                {
                    cout << word << " ";
                }
                cout << "\n";
                cout << R"(
=============================================================
)";

                break;
            }
        }

        // option to play again
        cout << "\nWould you like to play again? (1 for Yes, 0 for No): ";
        int play_again;
        cin >> play_again;
        if (play_again != 1)
        {
            cout << "Thanks for playing! \n";
            break;
        }
    }

    return 0;
}