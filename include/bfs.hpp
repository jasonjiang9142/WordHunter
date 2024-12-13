#include <iostream>
#include <set>
#include <queue>
using namespace std;

bool bfs(vector<vector<char>> &grid, string word, int grid_size, int row, int col, vector<vector<bool>> &visited);

int bfswrapper(vector<vector<char>> grid, string word, int score, int grid_size, set<string> &visited);