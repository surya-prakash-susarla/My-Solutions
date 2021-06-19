#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int n, m;

void djikstra(vector<vector<int>> graph, vector<int> &dist,
              vector<bool> &covered) {
  /*
  cout<<"dist array is " <<endl ;
  for(int i=0;i<n;i++)
          cout<<dist[i]<<" ";
  cout<<endl;
  cout<<"covered array is "<<endl;
  for(int i=0;i<n;i++)
          cout<<covered[i]<< " ";
  */
  int lowest_value = -1, lowest_index = -1;
  for (int i = 0; i < n; i++) {
    if (not covered[i] and dist[i] != -1) {
      if (lowest_value == -1 or lowest_value > dist[i]) {
        lowest_value = dist[i];
        lowest_index = i;
      }
    }
  }
  // cout<<"lowest index is " << lowest_index<<endl;
  if (lowest_index == -1)
    return;
  covered[lowest_index] = true;
  for (int i = 0; i < n; i++) {
    if (not covered[i]) {
      if (graph[lowest_index][i] != -1 and
          (dist[i] == -1 or dist[i] > graph[lowest_index][i] | lowest_value))
        dist[i] = graph[lowest_index][i] | lowest_value;
    }
  }
  djikstra(graph, dist, covered);
}

int main() {
  cin >> n >> m;
  vector<int> dist(n, -1);
  vector<bool> covered(n, false);
  vector<vector<int>> graph(n, vector<int>(n, -1));
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a -= 1;
    b -= 1;
    if (graph[a][b] == -1 or graph[a][b] > c)
      graph[a][b] = c;
  }
  /*
  for(int i=0;i<n;i++){
      for(int j=0;j<n;j++)
          cout<<graph[i][j]<< " ";
      cout<<endl;
  }
  */
  int start, end;
  cin >> start >> end;
  start -= 1;
  end -= 1;
  dist[start] = 0;
  djikstra(graph, dist, covered);
  cout << dist[end] << endl;
}