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
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    vector<bool> visited(rooms.size(), false);
    set<int> current(rooms[0].begin(), rooms[0].end());

    visited[0] = true;

    while (not current.empty()) {
      set<int> next;
      for (int i : current) {
        visited[i] = true;
        for (int j : rooms[i])
          if (not visited[j])
            next.insert(j);
      }
      swap(current, next);
    }

    for (bool i : visited)
      if (not i)
        return false;
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
