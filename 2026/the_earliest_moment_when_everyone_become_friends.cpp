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
  class uf {
   public:
    uf(int n) {
      roots = n;
      parents = vector<int>(n, -1);
      depth = vector<int>(n, 1);
    }

    int find_parent(int n) {
      if (parents[n] == -1)
        return n;

      // path compression.
      return parents[n] = find_parent(parents[n]);
    }

    void merge(int a, int b) {
      int p1 = find_parent(a);
      int p2 = find_parent(b);
      if (p1 == p2) {
        // already connected.
        return;
      }
      roots--;
      if (depth[p1] > depth[p2]) {
        depth[p1] += depth[p2];
        parents[p2] = p1;
      } else {
        depth[p2] += depth[p1];
        parents[p1] = p2;
      }
    }

    int get_roots() { return roots; }

   private:
    int roots;
    vector<int> parents;
    vector<int> depth;
  };

  int earliestAcq(vector<vector<int>>& logs, int n) {
    sort(logs.begin(), logs.end(),
         [](const vector<int>& a, const vector<int>& b) {
           if (a[0] == b[0])
             return a[1] < b[1];
           return a[0] < b[0];
         });
    uf cons(n);
    for (auto i : logs) {
      cons.merge(i[1], i[2]);
      if (cons.get_roots() == 1)
        return i[0];
    }
    return -1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
