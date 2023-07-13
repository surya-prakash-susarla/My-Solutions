#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& values) {
    vector<int> prefix(values.size(), 1);
    vector<int> suffix(values.size(), 1);

    prefix[0] = values[0];
    *suffix.rbegin() = *values.rbegin();

    for (int i = 1; i < values.size(); i++) {
      prefix[i] = prefix[i - 1] * values[i];
    }

    for (int i = values.size() - 2; i > -1; i--) {
      suffix[i] = suffix[i + 1] * values[i];
    }

    vector<int> answer(values.size());

    answer[0] = suffix[1];
    answer[answer.size() - 1] = prefix[answer.size() - 2];

    for (int i = 1; i < answer.size() - 1; i++) {
      answer[i] = prefix[i - 1] * suffix[i + 1];
    }

    return answer;
  }
};

int main() {
  return 0;
}
