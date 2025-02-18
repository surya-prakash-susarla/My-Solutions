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
  vector<int> topKFrequent(vector<int>& input, int k) {
    unordered_map<int, int> counts;
    for (int i : input)
      counts[i]++;

    priority_queue<pair<int, int>> values;
    for (auto i : counts)
      values.push({i.second, i.first});

    vector<int> answer;
    while (k) {
      answer.push_back(values.top().second);
      values.pop();
      k--;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
