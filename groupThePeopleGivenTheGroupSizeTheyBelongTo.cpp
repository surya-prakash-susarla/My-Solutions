#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    map<int, vector<int>> groups;
    for (int i = 0; i < groupSizes.size(); i++) {
      auto g = groups.find(groupSizes[i]);
      if (g != groups.end())
        g->second.push_back(i);
      else
        g.insert(make_pair<int, vector<int>>(groupSizes[i], {i}));
    }
    vector<vector<int>> values;
    for (auto it = groups.begin(); it != groups.end(); it++) {
      if (it->second.size() % it->first != 0)
        return {{}};
      auto start = it->second.begin();
      vector<int> inner_values;
      while (start != it->second.end()) {
        inner_values.insert(inner_values.end(), start, start + it->first);
        start = start + it->first;
      }
      values.push_back(inner_values);
    }
    return values;
  }
};