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


// Problem:
// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
 public:
  vector<int> minOperations(string input) {
    vector<int> indices;
    for (int i = 0; i < input.size(); i++)
      if (input[i] == '1')
        indices.push_back(i);
    vector<int> answer(input.size());

    for (int i = 0; i < answer.size(); i++) {
      int temp = 0;
      for (const int j : indices)
        temp += (abs(j - i));
      answer[i] = temp;
    }

    return answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
