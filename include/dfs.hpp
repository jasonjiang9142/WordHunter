#include <iostream>
#include <set>
#include <queue>
using namespace std;

bool dfs(vector<vector<char>> &grid, string word, int grid_size, int pointer, int row, int col, vector<vector<bool>> &visited);

int dfswrapper(vector<vector<char>> grid, string word, int score, int grid_size, set<string> &visited);
