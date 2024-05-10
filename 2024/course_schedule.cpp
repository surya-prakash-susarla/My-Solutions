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
  bool canFinish(int n, vector<vector<int>>& dep) {
    vector<int> req(n, 0);
    map<int, vector<int>> cons;

    for (auto i : dep) {
      cons[i[1]].push_back(i[0]);
      req[i[0]]++;
    }

    queue<int> courses;
    for (int i = 0; i < n; i++)
      if (req[i] == 0)
        courses.push(i);

    while (not courses.empty()) {
      queue<int> next;
      while (not courses.empty()) {
        int temp = courses.front();
        courses.pop();
        for (int i : cons[temp]) {
          req[i] = max(0, req[i] - 1);
          if (req[i] == 0)
            next.push(i);
        }
      }
      swap(next, courses);
    }

    for (int i : req)
      if (i > 0)
        return false;

    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
