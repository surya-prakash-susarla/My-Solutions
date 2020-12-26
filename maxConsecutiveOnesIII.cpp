#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int get(const int& req,
          const vector<int>& zero,
          const int& k,
          const int& max_size) {
    int index = 0;
    while (index < zero.size())
      if (zero[index] >= req)
        break;
      else
        index++;
    if (index + k >= zero.size())
      return max_size;
    return zero[index + k] - 1;
  }

  int longestOnes(vector<int>& input, int k) {
    vector<int> zero;
    for (int i = 0; i < input.size(); i++)
      if (input[i] == 0)
        zero.push_back(i);
    int answer = -1;
    for (int i = 0; i < input.size(); i++) {
      int limit = get(i, zero, k, input.size() - 1);
      answer = max(answer, limit - i + 1);
      if (limit == input.size() - 1)
        break;
    }
    return answer;
  }
};