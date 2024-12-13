#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <tuple>
#include <algorithm> // For std::transform
#include <cctype>    // For ::tolower
#include <iomanip>
using namespace std;

char getLetter();
vector<vector<char>> createGrid(int gridSize);
void printGrid(const vector<vector<char>> &grid);
