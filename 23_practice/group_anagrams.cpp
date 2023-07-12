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
  string sorted(string input) {
    sort(input.begin(), input.end());
    return input;
  }

  vector<vector<string>> groupAnagrams(vector<string>& input) {
    unordered_map<string, vector<string>> values;
    for (string i : input) {
      values[sorted(i)].emplace_back(i);
    }

    vector<vector<string>> answer;
    for (auto i : values) {
      answer.emplace_back(i.second);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
