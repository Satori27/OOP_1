#pragma once
#include <cmath>
#include <iostream>
#include <unordered_set>
#include <utility>

using namespace std;

void loop_for_n(int number, int m, pair<int, int> &answer, unordered_set<int> &square_of_numbers);
pair<int, int> closest_pair_tonum(int number);