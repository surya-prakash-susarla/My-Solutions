#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

// Problem: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
 public:
#define get(c) c - 'a'

  inline int __fmin__(const std::vector<int>& values) {
    int val = numeric_limits<int>::max();
    int index = -1;
    for (int i = 0; i < values.size(); i++) {
      if (values[i] != 0) {
        if (values[i] < val) {
          val = values[i];
          index = i;
        }
      }
    }
    return index;
  }

  int beautySum(string s) {
    int answer = 0;
    vector<int> values(26, 0);

    int maxval = -1, minval = -1;

    for (int i = 0; i < s.size(); i++) {
      int start_index = get(s[i]);
      values[start_index] = 1;
      minval = start_index;
      maxval = start_index;

      for (int j = i + 1; j < s.size(); j++) {
        const int ci = get(s[j]);

        values[ci]++;

        if (values[ci] > values[maxval])
          maxval = ci;

        if (ci == minval) {
          minval = __fmin__(values);
        } else if (values[ci] < values[minval])
          minval = ci;

        answer += (values[maxval] - values[minval]);
      }

      fill(values.begin(), values.end(), 0);
    }

    return answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  string value;
  cin >> value;

  Solution temp;

  const int answer = temp.beautySum(value);

  cout << "FINAL ANSWER : " << answer << endl;

  return 0;
}
