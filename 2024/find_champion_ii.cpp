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
  int findChampion(int n, vector<vector<int>>& edges) {
    unordered_map<int, bool> hits;

    for (const vector<int>& i : edges) {
      hits[i[0]] = hits[i[0]] or false;
      hits[i[1]] = true;
    }

    for (int i = 0; i < n; i++)
      hits[i] = hits[i] or false;

    int answer = INT_MAX;
    for (auto i : hits)
      if (not i.second)
        if (answer == INT_MAX)
          answer = i.first;
        else
          return -1;

    return answer == INT_MAX ? -1 : answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
