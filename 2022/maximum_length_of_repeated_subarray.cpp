#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findLength(vector<int>& a, vector<int>& b) {
    vector<vector<pair<int, int>>> values(a.size());

    int answer = 0;

    for (int i = 0; i < b.size(); i++) {
      if (b[i] == *a.rbegin()) {
        values[a.size() - 1].push_back({i, i});
        answer = max(answer, 1);
      }
    }
    for (int i = a.size() - 2; i > -1; i--) {
      vector<bool> indices(b.size(), false);
      for (const pair<int, int>& j : values[i + 1])
        if (j.first - 1 > -1 and b[j.first - 1] == a[i]) {
          values[i].push_back({j.first - 1, j.second});
          indices[j.first - 1] = true;
          answer = max(answer, j.second - j.first + 2);
        }
      for (int j = 0; j < b.size(); j++)
        if (not indices[j] and b[j] == a[i]) {
          answer = max(answer, 1);
          values[i].push_back({j, j});
        }
    }
    return answer;
  }
};

int main() {
  return 0;
}
