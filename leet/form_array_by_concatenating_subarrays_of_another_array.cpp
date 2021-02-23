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

// Problem: https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/submissions/
// Bi-weekly contest 46

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
 public:
  vector<vector<int>> locations;

  bool __rec__(const int index,
               const int prev_limit,
               const vector<vector<int>>& groups) {
    if (index >= groups.size())
      return true;
    for (const int i : locations[index]) {
      if (i > prev_limit) {
        bool result =
            __rec__(index + 1, i + (groups[index].size() - 1), groups);
        if (result)
          return true;
      }
    }
    return false;
  }

  void __find_locations__(const vector<vector<int>>& groups,
                          const vector<int>& input) {
    locations.resize(groups.size());
    vector<int> indices(groups.size());

    for (int i = 0; i < input.size(); i++) {
      for (int j = 0; j < groups.size(); j++) {
        if (input[i] == groups[j][indices[j]]) {
          indices[j]++;
          if (indices[j] == groups[j].size()) {
            indices[j] = 0;
            locations[j].push_back(i - groups[j].size() + 1);
          }
        } else {
          indices[j] = 0;
          if (groups[j][indices[j]] == input[i])
            indices[j]++;
        }
      }
    }
    return;
  }

  bool __trivial_check_fail__(const vector<vector<int>>& groups,
                         const vector<int>& input) {
    int size = 0;
    for (const vector<int>& i : groups)
      size += i.size();
    return size > input.size();
  }

  bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
    if (__trivial_check_fail__(groups, nums))
      return false;
    __find_locations__(groups, nums);
    return __rec__(0, -1, groups);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  int gs;
  std::cin >> gs;
  vector<vector<int>> groups(gs);
  for (vector<int>& i : groups) {
    int temp;
    std::cin >> temp;
    for (int j = 0; j < temp; j++) {
      int test;
      std::cin >> test;
      i.push_back(test);
    }
  }
  std::cout << "groups input done" << std::endl;
  int ns;
  std::cin >> ns;
  std::cout << "ns value : " << ns << std::endl;
  vector<int> input(ns);
  for (int i = 0; i < ns; i++)
    std::cin >> input[i];

  std::cout << "input complete , starting ops " << std::endl;

  Solution temp;
  bool answer = temp.canChoose(groups, input);
  std::cout << "FINAL ANSWER : " << (int)answer << std::endl;

  return 0;
}
