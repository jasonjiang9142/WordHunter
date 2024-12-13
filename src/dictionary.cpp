#include "../include/dictionary.hpp"

// Function to load the dictionary from the wordlist.txt file
set<string> loadDictionary(const string &filename)
{
    set<string> dictionary;
    ifstream file(filename);

    if (!file)
    {
        cerr << "Error opening dictionary file." << endl;
        return dictionary;
    }

    string word;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    while (file >> word)
    {
        dictionary.insert(word); // Add each word to the set
    }
    return dictionary;
}
