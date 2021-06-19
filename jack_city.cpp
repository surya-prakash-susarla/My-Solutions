#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/*
void printer( vector<int> final_distances ) {
  for ( int i=0 ;i <final_distances.size() ;i ++)
   cout<< final_distances[i]<<" ";
   cout<<endl;
  return;
}
*/

int nodes, edges;

void djik(int node, vector<vector<pair<int, int>>> &adlist,
          vector<bool> &covered, vector<int> &final_distances) {
  if (node == -1) {
    // cout << "returning since the value of node is "<<-1<<endl;
    return;
  }
  // cout << "updating distances of adjacent nodes to "<<node<<endl;
  for (int i = 0; i < adlist[node].size(); i++) {
    int &d1 = final_distances[adlist[node][i].first];
    int ti = adlist[node][i].second - final_distances[node];
    if (ti < 0)
      ti = 0;
    int new_value = final_distances[node] + ti;
    if (d1 == -1 or (new_value < d1))
      d1 = new_value;
  }
  covered[node] = true;
  // cout<<"printing the values of the final distances array "<<endl;
  // printer(final_distances) ;
  // cout << " covered node "<<node <<endl;
  int minval = -1, minind = -1;
  for (int i = 0; i < nodes; i++)
    if (not covered[i] and final_distances[i] != -1 and
        (minval == -1 or final_distances[i] < minval)) {
      minval = final_distances[i];
      minind = i;
    }
  djik(minind, adlist, covered, final_distances);
  // cout<<"returning from "<<node <<endl;
  return;
}

int main(int argc, char const *argv[]) {
  // cout <<" enter the number of nodes and edges "<<endl;
  cin >> nodes >> edges;
  vector<vector<pair<int, int>>> adlist(nodes);
  // cout<<"enter the edges "<<endl;
  for (int i = 0; i < edges; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a -= 1;
    b -= 1;
    adlist[a].push_back(make_pair(b, c));
    adlist[b].push_back(make_pair(a, c));
  }
  vector<int> final_distances(nodes, -1);
  vector<bool> covered(nodes, false);
  // cout<<"calling the function "<<endl;
  final_distances[0] = 0;
  djik(0, adlist, covered, final_distances);
  // cout<<"completed calculations "<<endl;
  int answer = final_distances[nodes - 1];
  if (answer == -1)
    cout << "NO PATH EXISTS" << endl;
  else
    cout << answer << endl;
  return 0;
}
