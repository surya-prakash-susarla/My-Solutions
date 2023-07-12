#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool check(int start, int end, const string& input) {
    while (start <= end)
      if (input[start++] != input[end--])
        return false;
    return true;
  }

  int countSubstrings(string input) {
    int answer = input.size();
    for (int i = 1; i < input.size(); i++)
      for (int j = 0; j + i < input.size(); j++)
        if (check(j, j + i, input))
          answer++;
    return answer;
  }
};