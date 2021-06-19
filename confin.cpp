#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, **a, *visited;
vector<int> paths;
bool visit(int e) {
  if (visited[e] == 1)
    return true;
  return false;
}
int unvisit() {
  for (int i = 0; i < n; i++)
    if (visited[i] == -1)
      return i;
  return -1;
}
int exist(int row) {
  for (int i = 0; i < n; i++)
    if (a[row][i] == 1)
      return i;
  return -1;
}
void dfs(int row) {
  for (int i = 0; i < n; i++)
    a[i][row] = 0;
  cout << "currently visiting " << row << endl << visit(row) << endl;
  if (visit(row))
    return;
  paths.push_back(row);
  visited[row] = 1;
  int ind = exist(row);
  cout << "index is = " << ind << endl << endl;
  while (ind != -1) {
    dfs(ind);
    ind = exist(row);
  }
}
int main() {
  cout << "enter the number of vertices" << endl;
  cin >> n;
  a = new int *[n];
  for (int i = 0; i < n; i++)
    a[i] = new int[n];
  cout << "enter the adjacency matrix" << endl;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];
  visited = new int[n];
  cout << "initializing visited matrix" << endl;
  for (int i = 0; i < n; i++)
    visited[i] = -1;
  int temp = unvisit();
  cout << "starting the dfs search from " << temp << " location" << endl;
  while (temp != -1) {
    cout << "locaiton of starting point " << temp << endl;
    dfs(temp);
    vector<int>::iterator it;
    for (it = paths.begin(); it != paths.end(); it++)
      cout << *it << "\t";
    paths.clear();
    temp = unvisit();
  }
  cout << "dfs call complete" << endl;
  return 0;
}
