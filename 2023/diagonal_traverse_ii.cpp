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
  vector<int> findDiagonalOrder(vector<vector<int>>& values) {
    map<int, list<int>> storage;

    for (int i = 0; i < values.size(); i++) {
      int col = i;
      for (int j = 0; j < values[i].size(); j++) {
        storage[col++].push_front(values[i][j]);
      }
    }

    vector<int> answer;
    for (auto i : storage)
      answer.insert(answer.end(), i.second.begin(), i.second.end());

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
