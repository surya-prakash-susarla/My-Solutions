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
  vector<vector<int>> merge(vector<vector<int>>& input) {
    sort(input.begin(), input.end(),
         [](const vector<int>& a, const vector<int>& b) {
           if (a[0] == b[0])
             return a[1] < b[1];
           return a[0] < b[0];
         });

    vector<vector<int>> answer;

    int left = input[0][0];
    int right = input[0][1];

    for (int i = 1; i < input.size(); i++) {
      if (right >= input[i][0])
        right = max(right, input[i][1]);
      else {
        answer.emplace_back(vector<int>{left, right});
        left = input[i][0];
        right = input[i][1];
      }
    }

    answer.emplace_back(vector<int>{left, right});

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
