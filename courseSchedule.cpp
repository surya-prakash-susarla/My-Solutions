#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool calc(int index,
            vector<bool> parents,
            vector<bool>& visited,
            const vector<vector<bool>>& edges) {
    if (parents[index])
      return false;
    if (visited[index])
      return true;
    parents[index] = true;
    visited[index] = true;
    for (int i = 0; i < edges.size(); i++)
      if (edges[index][i] and not calc(i, parents, visited, edges))
        return false;
    return true;
  }

  bool canFinish(int n, vector<vector<int>>& course) {
    vector<bool> ind(n, true), visited(n, false);
    vector<vector<bool>> edges(n, vector<bool>(n, false));
    for (const vector<int>& i : course) {
      edges[i[0]][i[1]] = true;
      ind[i[1]] = false;
    }
    bool one = false;
    for (int i = 0; i < n; i++) {
      if (ind[i])
        one = true;
      if (not calc(i, vector<bool>(n, false), visited, edges))
        return false;
    }
    if (not one)
      return false;
    return true;
  }
};