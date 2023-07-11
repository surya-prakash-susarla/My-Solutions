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
  vector<vector<int>> threeSum(vector<int>& input) {
    typedef pair<int, int> pint;
    unordered_map<int, vector<pint>> values;

    map<int, int> counts;
    for (int i : input)
      counts[i]++;
    vector<int> temp;
    for (const pint& i : counts) {
      temp.push_back(i.first);
      if (i.second > 1)
        temp.push_back(i.first);
      if (i.second > 2 and i.first == 0)
        temp.push_back(0);
    }

    input = temp;
    int n = input.size();

    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        values[input[i] + input[j]].emplace_back(make_pair(i, j));

    set<vector<int>> answer;

    for (int i = 0; i < n; i++) {
      const vector<pint>& options = values[0 - input[i]];
      for (const pint& j : options)
        if (i < j.first)
          answer.insert({input[i], input[j.first], input[j.second]});
    }

    return vector<vector<int>>(answer.begin(), answer.end());
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
