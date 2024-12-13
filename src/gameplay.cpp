
#include "../include/gameplay.hpp"

// prints the resulting words
void print_results(int current_score, vector<string> correct_words)
{

    cout << R"( 
=============================================================
                      Game Over!
=============================================================

Your total Score was: )"
         << current_score << R"(
You got )"
         << correct_words.size()
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

    return;
}

// prints the rules for the game
void print_rules()
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

    return;
}

int choose_mode()
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

    return mode;
}

// prints the game play
void play_game()
{
    print_rules();
    // Wait for user input before continuing
    cin.get();

    // Load the dictionary from wordlist.txt
    set<string>
        dictionary = loadDictionary("wordlist.txt");

    while (true)
    {
        // let the user choose the mode
        int mode = choose_mode();

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

        // create the grid base in the mode
        vector<vector<char>> grid = createGrid(grid_size);

        // intialize our timer and basic game variables
        auto start_time = chrono::high_resolution_clock::now();
        cout << "You have " << time_limit << " seconds to play!\n";

        int current_score = 0;
        set<string> visited;
        vector<string> correct_words;

        // keep iterating while a game is going on
        while (true)
        {
            // constantly checking the time
            auto now_time = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_time = now_time - start_time;

            // Display grid, current score, and remaining time
            cout << "\nGrid: \n\n";
            printGrid(grid);
            cout << "\nCurrent Score: " << current_score << "\n";

            // check to see if there is still time left
            int time_left = time_limit - int(elapsed_time.count());
            if (time_left <= 0)
            {
                print_results(current_score, correct_words);
                break;
            }
            else
            {
                cout << "Time Left: " << time_limit - int(elapsed_time.count()) << " seconds\n";
            }

            // Ask for user input and transform that input to lowercase
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

            // check if the word is at least length of 3
            else if (input_word.length() < 3)
            {
                cout << "You need a word of at least length 3. Try again. \n";
                continue;
            }

            // perform dfs and returns the new score
            int new_score = dfswrapper(grid, input_word, current_score, grid_size, visited);
            // int new_score = bfswrapper(grid, input_word, current_score, grid_size, visited);

            // to see if we have new score
            if (new_score > current_score)
            {
                correct_words.push_back(input_word);
            }
            current_score = new_score;

            if (elapsed_time.count() >= time_limit)
            {
                print_results(current_score, correct_words);
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
}