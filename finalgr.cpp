#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long int n, m, **a, *visited, cl, cr, q, t;
vector<long long int> paths;
bool visit(long long int e) {
  if (visited[e] == 1)
    return true;
  return false;
}
long long int unvisit() {
  for (long long int i = 0; i < n; i++)
    if (visited[i] == -1)
      return i;
  return -1;
}
long long int exist(long long int row) {
  for (long long int i = 0; i < n; i++)
    if (a[row][i] == 1)
      return i;
  return -1;
}
void dfs(long long int row) {
  for (long long int i = 0; i < n; i++)
    a[i][row] = 0;
  if (visit(row))
    return;
  paths.push_back(row);
  visited[row] = 1;
  long long int ind = exist(row);
  // cout<<"index is = "<<ind<<endl<<endl;
  while (ind != -1) {
    dfs(ind);
    ind = exist(row);
  }
}
int main() {
  // cout<<"enter the number of queries"<<endl;
  cin >> q;
  while (q-- > 0) {
    //	cout<<"enter the cities, roads, lib cost , road cost"<<endl;
    cin >> n >> m >> cl >> cr;
    a = new long long int *[n];
    for (long long int i = 0; i < n; i++) {
      a[i] = new long long int[n];
      for (long long int j = 0; j < n; j++)
        a[i][j] = 0;
    }
    //	cout<<"enter the road connections"<<endl;
    for (long long int i = 0; i < m; i++) {
      long long int g, h;
      cin >> g >> h;
      a[g - 1][h - 1] = 1;
      a[h - 1][g - 1] = 1;
    }
    if (cr > cl) {
      cout << n * cl << endl;
    } else {
      visited = new long long int[n];
      for (long long int i = 0; i < n; i++)
        visited[i] = -1;
      long long int temp = unvisit();
      long long int sum = 0;
      //	cout<<"calculating connected components using dfs"<<endl;
      while (temp != -1) {
        dfs(temp);
        long long int net_s = paths.size();
        //		vector<long long int>::iterator it;
        //		for(it=paths.begin();it!=paths.end();it++)
        //			cout<<*it<<"\t";
        //		cout<<endl;
        paths.clear();
        temp = unvisit();
        sum += cr * (net_s - 1) + cl;
      }
      cout << sum << endl;
    }
  }
  // cout<<"at the end of the main function"<<endl;
  return 0;
}
