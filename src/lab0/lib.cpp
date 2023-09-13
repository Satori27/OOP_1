// Copyright 2023 SomeName
#include "lib.h"

pair<int, int> closest_pair_tonum(int number) {
  pair<int, int> answer;
  if (number > 6000 || !static_cast<int>(number) || number<=0) {
	return answer = {0, 0};
  }
  unordered_set<int> square_of_numbers;
  int num_to_find_sq = number * 2;
  for (int sqrt_of_num = 1; sqrt_of_num <= sqrt(num_to_find_sq); ++sqrt_of_num) {
	square_of_numbers.insert(sqrt_of_num*sqrt_of_num);
  }

  for (int num_to_find_m = 1; num_to_find_m < number - 1; ++num_to_find_m) {
	int m = number - num_to_find_m;
	for (int num_to_find_n = 1; num_to_find_n < number - 1; ++num_to_find_n) {
	  int n = number - num_to_find_n;
	  auto sq_end = square_of_numbers.end();
	  auto sq_find_sum = square_of_numbers.find(m + n);
	  auto sq_find_dif = square_of_numbers.find(m - n);
	  if ((sq_find_sum != sq_end && sq_find_dif != sq_end)) {
		if (m > answer.first || (m == answer.first && n > answer.second)) {
		  answer = {m, n};
		}
	  }
	}
  }
  return answer;
}