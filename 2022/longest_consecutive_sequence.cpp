#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& values) {
    if (values.size() == 0)
      return 0;

    sort(values.begin(), values.end());

    int answer = 1;
    int current = 1;

    for (int i = 1; i < values.size(); i++) {
      if (values[i] == values[i - 1] + 1) {
        answer = max(answer, ++current);
      } else if (values[i] == values[i - 1]) {
        continue;
      } else {
        current = 1;
      }
    }

    return answer;
  }
};

int main() {
  return 0;
}
