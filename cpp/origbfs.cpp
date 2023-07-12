#include <iostream>
using namespace std;
int **a, n, *dists;
bool *vis;
void bfs_traversal(int row, int val) {
  vis[row] = true;
  //	cout<<row<<"\t";
  //	for(int i=0;i<n;i++)
  //		if(a[row][i]==1 and not vis[i])
  //			cout<<i<<"\t";
  for (int i = 0; i < n; i++)
    if (a[row][i] == 1 and not vis[i]) {
      if (dists[i] = -1 or val < dists[i])
        dists[i] = val;
      bfs_traversal(i, val + 6);
    }
}
int main() {
  int q;
  cin >> q;
  while (q-- > 0) {
    int rels;
    cin >> n >> rels;
    a = new int *[n];
    vis = new bool[n];
    dists = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = new int[n];
      vis[i] = false;
      dists[i] = -1;
      for (int j = 0; j < n; j++) {
        a[i][j] = 0;
      }
    }
    for (int i = 0; i < rels; i++) {
      int g, h;
      cin >> g >> h;
      a[g - 1][h - 1] = 1;
      a[h - 1][g - 1] = 1;
    }
    int start;
    cin >> start;
    /*	cout<<"the adjacency matrix is as follows:"<<endl;
            for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++)
                            cout<<a[i][j]<<" ";
                    cout<<endl;
            }
    */
    //	cout<<"the bfs path is :"<<endl;
    //	cout<<start<<"\t";
    start -= 1;
    dists[start] = 0;
    bfs_traversal(start, 6);
    //	cout<<endl;
    //	cout<<"the distances from the given starting point are as
    //follows:"<<endl;
    for (int i = 0; i < n; i++)
      if (i != start)
        cout << dists[i] << " ";
    cout << endl;
  }
  return 0;
}
