#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int **a, n, s, t, init, g, se, p;
vector<int> visited, vals;
int searcher(int row, int val) {
  // cout<<"currently searching "<<row<<endl;
  if (find(visited.begin(), visited.end(), row) != visited.end())
    return -1;
  else
    visited.push_back(row);
  if (a[row][t] == 1)
    return val + 1;
  for (int i = 0; i < n; i++) {
    if (a[row][i] == 1) {
      int temp = searcher(i, val + 1);
      if (temp >= 0)
        vals.push_back(temp);
    }
  }
  return -1;
}
int main() {
  cin >> n >> s >> t >> init >> g >> se >> p;
  a = new int *[n];
  for (int i = 0; i < n; i++)
    a[i] = new int[n];
  int *r = new int[n];
  r[0] = init;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      a[i][j] = 0;
  for (int i = 1; i < n; i++)
    r[i] = (r[i - 1] * g + se) % p;
  for (int i = 0; i < n; i++) {
    int t = 1;
    while (t <= r[i]) {
      a[i][(i + t) % n] = 1;
      if (i < t)
        a[i][(n + i - t)] = 1;
      else
        a[i][i - t] = 1;
      t++;
    }
  }
  // cout<<"the adjacency matrix is "<<endl;
  // for(int i=0;i<n;i++){
  //	for(int j=0;j<n;j++)
  //		cout<<a[i][j]<<"\t";
  //	cout<<endl;
  //}
  // cout<<"before the function call"<<endl;
  int temp = searcher(s, 0);
  // cout<<endl<<"after searching function"<<endl;
  auto result = min_element(vals.begin(), vals.end());
  if (result != end(vals))
    cout << *result << endl;
  return 0;
}
