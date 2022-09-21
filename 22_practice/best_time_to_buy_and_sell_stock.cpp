#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& values) {
    vector<int> maxvalues(values.begin(), values.end());

    for (int i = values.size() - 2; i > -1; i--) {
      maxvalues[i] = max(maxvalues[i], maxvalues[i + 1]);
    }

    int answer = 0;

    for (int i = 0; i < values.size(); i++) {
      answer = max(answer, maxvalues[i] - values[i]);
    }

    return answer;
  }
};

int main() {
  return 0;
}
