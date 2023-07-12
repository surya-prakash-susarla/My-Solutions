#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int llint;
const llint high = 99999999;
llint n, m;
bool *visited;
llint **data, *distances;

llint find_shortest() {
  // cout<<"searching for element with lowest weight"<<endl;
  llint mini = -1, mindex = -1;
  for (llint i = 1; i < n; i++) {
    if (distances[i] != high and not visited[i] and
        (mini == -1 or distances[i] < mini)) {
      mindex = i;
      mini = distances[i];
    }
  }
  // cout<<"found lowest weight at
  // "<<mindex<<"\tweight="<<distances[mindex]<<endl;
  return mindex;
}

void path_finder() {
  llint index = find_shortest();
  if (index == -1) {
    // cout<<"all elements covered , returning from the function"<<endl;
    return;
  }
  // cout<<"currently checking for "<<index<<endl;
  visited[index] = true;
  for (llint i = 1; i < n; i++) {
    if (data[index][i] != -1 and not visited[i] and
        (distances[i] == high or
         distances[index] + data[index][i] < distances[i])) {
      // cout<<"marking new distances for "<<i<<"from "<<index<<endl;
      distances[i] = distances[index] + data[index][i];
    }
  }
  // cout<<"completed all marking from "<<index<<endl;
  // cout<<"NEW FUNCTION CALL BEGINS HERE"<<endl;
  path_finder();
  return;
}

int main() {
  llint t;
  // cout<<"enter the number of test cases"<<endl;
  cin >> t;
  while (t-- > 0) {
    // cout<<"enter the number of vertices and links"<<endl;
    cin >> n >> m;
    n = n + 1;
    data = new llint *[n];
    visited = new bool[n];
    distances = new llint[n];
    for (llint i = 1; i < n; i++) {
      data[i] = new llint[n];
      visited[i] = false;
      distances[i] = high;
      for (llint j = 1; j < n; j++)
        data[i][j] = -1;
    }
    // cout<<"enter the links"<<endl;
    for (llint i = 0; i < m; i++) {
      llint a, b, l;
      cin >> a >> b >> l;
      if ((data[b][a] == -1 and data[a][b] == -1) or data[a][b] > l) {
        data[a][b] = l;
        data[b][a] = l;
      }
    }
    // cout<<"enter the source node"<<endl;
    llint start;
    cin >> start;
    distances[start] = 0;
    // cout<<"the function call starts"<<endl;
    // function call start from this place
    path_finder();
    // cout<<"function call completed "<<endl;
    // cout<<"the final distances to all the nodes are "<<endl;
    for (llint i = 1; i < n; i++) {
      if (i != start) {
        if (distances[i] != high)
          cout << distances[i] << " ";
        else
          cout << "-1 ";
      }
    }
    if (t > 0)
      cout << endl;
  }
  // cout<<"program terminated"<<endl;
  return 0;
}
