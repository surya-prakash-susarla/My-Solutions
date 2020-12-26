#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void calc(int index,
            vector<bool>& visited,
            const vector<vector<int>>& input) {
    visited[index] = true;
    for (int i = 0; i < input.size(); i++)
      if (input[index][i] and not visited[i])
        calc(i, visited, input);
    return;
  }

  int findCircleNum(vector<vector<int>>& input) {
    vector<bool> visited(input.size(), false);
    int answer = 0;
    for (int i = 0; i < input.size(); i++)
      if (not visited[i]) {
        answer++;
        calc(i, visited, input);
      }
    return answer;
  }
};