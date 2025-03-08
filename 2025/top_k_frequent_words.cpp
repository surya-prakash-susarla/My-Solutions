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
  vector<string> topKFrequent(vector<string>& input, int k) {
    map<string, int> counter;
    for (const string& i : input)
      counter[i]++;

    vector<pair<int, string>> values;
    for (auto i : counter)
      values.push_back({i.second, i.first});

    sort(values.begin(), values.end(),
         [](const pair<int, string>& a, const pair<int, string>& b) {
           if (a.first == b.first)
             return a.second < b.second;

           return a.first > b.first;
         });

    vector<string> answer;
    for (int i = 0; i < min((int)values.size(), k); i++)
      answer.emplace_back(values[i].second);

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
