#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> visited, vals;
int **a, n, s, d;
int searcher(int row, int val) {
  // cout<<"current row is "<<row<<endl;
  if (find(visited.begin(), visited.end(), row) != visited.end())
    return -1;
  else
    visited.push_back(row);
  if (a[row][d] == 1)
    return val + 1;
  // cout<<"Checking for further nodes from the root node"<<endl;
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
  cin >> n;
  a = new int *[n];
  for (int i = 0; i < n; i++)
    a[i] = new int[n];
  // cout<<"enter the adjacency matrix"<<endl;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];
  cin >> s >> d;
  int temp = searcher(s, 0);
  vector<int>::iterator it;
  // cout<<"printing the values of destination path"<<endl;
  // for (it = vals.begin();it!=vals.end();it++)
  //	cout<<*it<<"\t";
  // cout<<"printing the visited nodes"<<endl;
  // for (it=visited.begin();it!=visited.end();it++)
  //	cout<<*it<<"\t";
  // cout<<"done and dusted"<<endl;
  //
  auto result = min_element(vals.begin(), vals.end());
  if (result != end(vals))
    cout << *result << endl;
  return 0;
}
