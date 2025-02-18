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
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    map<string, int> email_mapping;

    for (int i = 0; i < accounts.size(); i++) {
      set<int> matching_ind;
      for (int j = 1; j < accounts[i].size(); j++) {
        auto it = email_mapping.find(accounts[i][j]);
        if (it != email_mapping.end()) {
          matching_ind.insert(it->second);
        }
      }
      if (matching_ind.empty()) {
        // cout << "no matching indices for base index : " << i << endl;
        for (int j = 1; j < accounts[i].size(); j++) {
          email_mapping[accounts[i][j]] = i;
        }
      } else {
        // cout << "for base index : " << i << ", matching indices" << endl;
        // for ( auto k : matching_ind )   cout << k << " ";
        // cout << endl;

        int merged_ind = *matching_ind.begin();
        for (auto k = email_mapping.begin(); k != email_mapping.end();
             k = next(k)) {
          if (matching_ind.contains(k->second))
            k->second = merged_ind;
        }
        for (int j = 1; j < accounts[i].size(); j++) {
          email_mapping[accounts[i][j]] = merged_ind;
        }
      }
    }

    map<int, set<string>> merged_list;
    for (auto i : email_mapping)
      merged_list[i.second].insert(i.first);

    vector<vector<string>> answer;
    for (auto i : merged_list) {
      vector<string> current;
      current.emplace_back(accounts[i.first][0]);
      for (auto j : i.second)
        current.emplace_back(j);

      answer.emplace_back(current);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
