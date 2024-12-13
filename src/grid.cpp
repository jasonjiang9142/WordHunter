#include "../include/grid.hpp"

// initialize a map to map the frequency of the letters
const map<char, double> letter_frequency = {
    {'a', 0.08167}, {'b', 0.01492}, {'c', 0.02782}, {'d', 0.04253}, {'e', 0.12702}, {'f', 0.02228}, {'g', 0.02015}, {'h', 0.06094}, {'i', 0.06966}, {'j', 0.00153}, {'k', 0.00772}, {'l', 0.04025}, {'m', 0.02406}, {'n', 0.06749}, {'o', 0.07507}, {'p', 0.01929}, {'q', 0.00095}, {'r', 0.05987}, {'s', 0.06327}, {'t', 0.09056}, {'u', 0.02758}, {'v', 0.00978}, {'w', 0.02360}, {'x', 0.00150}, {'y', 0.01974}, {'z', 0.00074}};

// initialize a list for bigrams and trigrams
const vector<string> bigrams = {"th", "he", "in", "en", "nt", "re", "er", "an", "ti", "es", "on", "at", "se", "nd", "or", "ar", "al", "te", "co", "de", "to", "ra", "et", "ed", "it", "sa", "em", "ro"};
const vector<string> trigrams = {"the", "and", "tha", "ent", "ing", "ion", "tio", "for", "nde", "has", "nce", "edt", "tis", "oft", "sth", "men"};

// creating a function to get the letter randomly
char getLetter()
{
    double random_val = static_cast<double>(rand()) / RAND_MAX;

    double cumulative = 0.0;

    // iterate through letter_freq
    for (const auto &pair : letter_frequency)
    {
        cumulative += pair.second;
        if (random_val <= cumulative)
        {
            return pair.first;
        };

        return 'e';
    }
    return 'e';
};

// creating a function to generate grid
vector<vector<char>> createGrid(int gridSize)
{
    // initialize a 2d list
    vector<vector<char>> grid(gridSize, vector<char>(gridSize));

    // seeding a random number generator
    srand(static_cast<unsigned>(time(0)));

    // iterate through the array and fill it in randomly
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            grid[i][j] = getLetter();
        }
    }

    tuple<int, int> coord[4] = {
        make_tuple(0, 1),
        make_tuple(0, -1),
        make_tuple(1, 0),
        make_tuple(-1, 0)};

    // iterate through bigrams now
    for (const auto &bigram : bigrams)
    {
        int x = rand() % (gridSize);
        int y = rand() % (gridSize);

        grid[x][y] = bigram[0];

        bool validPlacement = false;

        while (!validPlacement)
        {
            int idx = rand() % 4;
            int dx = get<0>(coord[idx]);
            int dy = get<1>(coord[idx]);

            if (0 <= (x + dx) && (x + dx) < gridSize && 0 <= (y + dy) && (y + dy) < gridSize)
            {
                grid[x + dx][y + dy] = bigram[1];
                validPlacement = true;
            }
        }
    }

    // iterate through trigrams now
    // Add a few trigrams to the grid
    for (const auto &trigram : trigrams)
    {
        int x = rand() % (gridSize - 2);
        int y = rand() % gridSize;
        grid[x][y] = trigram[0];
        grid[x + 1][y] = trigram[1];
        grid[x + 2][y] = trigram[2];
    }

    return grid;
}

// Function to print the grid
void printGrid(const vector<vector<char>> &grid)
{
    // Print the top row with column indices

    // Print the separator line after the column indices
    cout << "    ";
    for (int col = 0; col < grid[0].size(); ++col)
    {
        cout << "----"; // Draw the horizontal line
    }
    cout << endl;

    // Loop through each row and print the grid
    for (int row = 0; row < grid.size(); ++row)
    {
        cout << setw(3) << row; // Print the row index on the left

        // Print the grid content in each cell
        for (int col = 0; col < grid[row].size(); ++col)
        {
            cout << "| " << grid[row][col] << " "; // Print each cell with a border
        }
        cout << "|" << endl; // Close the row with a vertical border

        // Print the separator line after each row
        cout << "    ";
        for (int col = 0; col < grid[0].size(); ++col)
        {
            cout << "----"; // Draw the horizontal line
        }
        cout << endl;
    }

    return;
}