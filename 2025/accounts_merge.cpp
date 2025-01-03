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
  vector<int> parents;

  int find(int i) {
    if (parents[i] == -1)
      return i;
    else
      return find(parents[i]);
  }

  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    map<string, vector<int>> emails;

    for (int i = 0; i < accounts.size(); i++) {
      for (int j = 1; j < accounts[i].size(); j++) {
        emails[accounts[i][j]].push_back(i);
      }
    }

    parents = vector<int>(accounts.size(), -1);

    auto merge = [&](const vector<int>& values) {
      const int main = find(values[0]);

      for (int i = 1; i < values.size(); i++) {
        int cp = find(values[i]);
        if (cp != main)
          parents[cp] = main;
      }
    };

    for (auto i : emails)
      merge(i.second);

    map<int, set<string>> temp;

    for (auto i : emails) {
      int ind = find(i.second[0]);
      temp[ind].insert(i.first);
    }

    vector<vector<string>> answer;
    for (auto i : temp) {
      vector<string> temp2;
      temp2.emplace_back(accounts[i.first][0]);
      temp2.insert(temp2.end(), i.second.begin(), i.second.end());
      answer.emplace_back(temp2);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
