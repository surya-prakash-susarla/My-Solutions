#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

typedef long long int llint;
typedef long long unsigned int ullint;

using namespace std;

class Solution {
 public:
  vector<int> minOperations(string input) {
    // left to right
    vector<int> right(input.size(), 0);
    {
      int init = 0;
      int count = 0;

      for (int i = 1; i < input.size(); i++) {
        if (input[i] == '1') {
          init += (i);
          count++;
        }
      }

      right[0] = init;
      for (int i = 1; i < right.size(); i++) {
        if (input[i] == '1') {
          count--;
          right[i] = right[i - 1] - count - 1;
        } else {
          right[i] = right[i - 1] - count;
        }
      }
    }
    // right to left
    vector<int> left(input.size(), 0);
    {
      int init = 0;
      int count = 0;
      for (int i = input.size() - 2; i > -1; i--) {
        if (input[i] == '1') {
          init += (input.size() - i - 1);
          count++;
        }
      }

      left[input.size() - 1] = init;
      for (int i = input.size() - 2; i > -1; i--) {
        if (input[i] == '1') {
          count--;
          left[i] = left[i + 1] - count - 1;
        } else {
          left[i] = left[i + 1] - count;
        }
      }
    }

    vector<int> answer(input.size(), 0);
    for (int i = 0; i < input.size(); i++)
      answer[i] = left[i] + right[i];

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
