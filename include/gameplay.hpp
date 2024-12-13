#include <iostream>
#include <chrono>
#include <thread>
#include <set>
#include <string>
#include <algorithm> // For std::transform
#include <cctype>    // For ::tolower
#include "grid.hpp"
#include "dictionary.hpp"
#include "dfs.hpp"
#include "bfs.hpp"

void print_results(int current_score, vector<string> correct_words);
void print_rules();
void play_game();