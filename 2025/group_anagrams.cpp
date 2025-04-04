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
  vector<vector<string>> groupAnagrams(vector<string>& input) {
    map<string, vector<string>> values;

    for (int i = 0; i < input.size(); i++) {
      string temp = input[i];
      sort(temp.begin(), temp.end());
      values[temp].emplace_back(input[i]);
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
