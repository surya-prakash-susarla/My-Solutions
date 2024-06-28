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
  long long maximumImportance(int n, vector<vector<int>>& cons) {
    typedef vector<int> vint;

    unordered_map<int, int> counts;

    for (const vint& i : cons) {
      counts[i[0]]++;
      counts[i[1]]++;
    }

    priority_queue<pair<int, int>> sorted_cities;
    for (auto i : counts)
      sorted_cities.push(make_pair(i.second, i.first));

    unordered_map<int, int> final_assignment;

    for (; not sorted_cities.empty(); sorted_cities.pop())
      final_assignment[sorted_cities.top().second] = n--;

    long long answer = 0;
    for (const vint& i : cons)
      answer += (final_assignment[i[0]] + final_assignment[i[1]]);

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
