#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, rels;
    cin >> n >> rels;
    int **dist = new int *[n];
    for (int i = 0; i < n; i++) {
      dist[i] = new int[n];
      for (int j = 0; j < n; j++)
        dist[i][j] = -1;
    }
    for (int i = 0; i < rels; i++) {
      int a, b;
      cin >> a >> b;
      dist[a - 1][b - 1] = 6;
      dist[b - 1][a - 1] = 6;
    }
    /*cout<<"printing the matrix"<<endl;
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                    cout<<dist[i][j]<<" ";
            cout<<endl;
    }*/
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        if (i == k)
          continue;
        for (int j = 0; j < n; j++) {
          //			cout<<"IJK="<<i<<j<<k;
          if (j == k || j == i)
            continue;
          if (dist[i][k] != -1 && dist[k][j] != -1) {
            int temp = dist[i][k] + dist[k][j];
            if (dist[i][j] == -1 || dist[i][j] > temp)
              dist[i][j] = temp;
          }
        }
      }
    }
    /*cout<<"after completion"<<endl;
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                    cout<<dist[i][j]<<" ";
            cout<<endl;
    }*/
    int cit;
    cin >> cit;
    cit -= 1;
    for (int i = 0; i < n; i++)
      if (i != cit)
        cout << dist[cit][i] << " ";
    cout << endl;
  }
  return 0;
}
