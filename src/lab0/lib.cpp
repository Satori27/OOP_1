// Copyright 2023 SomeName
#include "lib.h"


void loop_for_n(int number, int m, pair < int, int > & answer, unordered_set < int > & square_of_numbers) {
    const auto sq_end = square_of_numbers.end();

    for (int num_to_find_n = 1; num_to_find_n < number - 1; ++num_to_find_n) {

        int n = number - num_to_find_n;
        bool check_square_sum = square_of_numbers.find(m + n) != sq_end;
        bool check_square_dif = square_of_numbers.find(m - n) != sq_end;
        bool check_condition = m > answer.first || (m == answer.first && n > answer.second);

        if (check_square_sum && check_square_dif && check_condition) {
            answer = {m, n};
        }
    }
}

pair < int, int > closest_pair_tonum(int number) {
    pair < int, int > answer = {-1,-1};

    if (number > 6000 || !static_cast < int > (number) || number <= 0) {
        return answer = {0,0};
    }

    unordered_set < int > square_of_numbers;
    int num_to_find_sq = number * 2;
    for (int sqrt_of_num = 1; sqrt_of_num <= sqrt(num_to_find_sq); ++sqrt_of_num) {
        square_of_numbers.insert(sqrt_of_num * sqrt_of_num);
    }

    for (int num_to_find_m = 1; num_to_find_m < number - 1; ++num_to_find_m) {
        int m = number - num_to_find_m;
        if (m < answer.first) break;
        loop_for_n(number, m, answer, square_of_numbers);
    }

    return answer;
}