#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  pair<int, int> calc(int index, const string& input) {
    index += 1;
    int score = 0;
    while (input[index] != ')') {
      pair<int, int> ret_value = calc(index, input);
      score += ret_value.first;
      index = ret_value.second + 1;
    }
    if (score == 0)
      return {1, index};
    return {2 * score, index};
  }

  int scoreOfParentheses(string input) {
    int index = 0, score = 0;
    while (index < input.size()) {
      pair<int, int> ret_value = calc(index, input);
      index = ret_value.second + 1, score += ret_value.first;
    }
    return score;
  }
};