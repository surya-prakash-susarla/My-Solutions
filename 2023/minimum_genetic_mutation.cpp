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
  bool can_use(const string& a, const string& b) {
    bool fault = false;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] != b[i]) {
        if (fault)
          return false;
        fault = true;
      }
    }
    return true;
  }

  int minMutation(string start, string end, vector<string>& bank) {
    int start_ind = -1;
    int end_ind = -1;

    {
      // find start and end indices.
      for (int i = 0; i < bank.size(); i++) {
        if (bank[i] == start) {
          start_ind = i;
          continue;
        }
        if (bank[i] == end) {
          end_ind = i;
        }
      }
      if (end_ind == -1) {
        return -1;
      }
      if (start_ind == -1) {
        bank.emplace_back(start);
        start_ind = bank.size() - 1;
      }
    }

    vector<vector<bool>> cons(bank.size(), vector<bool>(bank.size()));

    // create connectivity graph.
    for (int i = 0; i < bank.size(); i++) {
      for (int j = i + 1; j < bank.size(); j++) {
        if (can_use(bank[i], bank[j])) {
          cons[i][j] = true;
          cons[j][i] = true;
        }
      }
    }

    // bfs to find jumps.
    int jumps = 0;
    queue<int> current;
    vector<bool> visited(bank.size() + 1);

    current.push(start_ind);
    while (not current.empty()) {
      queue<int> next;
      jumps++;
      while (not current.empty()) {
        int ind = current.front();
        current.pop();
        if (ind == end_ind) {
          return jumps - 1;
        }
        if (visited[ind])
          continue;
        visited[ind] = true;
        for (int i = 0; i < bank.size(); i++) {
          if (cons[ind][i] and not visited[i])
            next.push(i);
        }
      }
      swap(current, next);
    }

    return -1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
