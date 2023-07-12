#include <iostream>
#include <vector>
using namespace std;

int mod(int a) {
  if (a < 0)
    return 0 - a;
  return a;
}

/*
void printer ( vector<int> a ) {
  for ( int i=0 ;i < a.size () ;i ++ )
     cout << a[i] <<" ";
   cout << endl;
  return;
}
*/

int nodes;

int maximum(vector<int> a) {
  int maxi = -1;
  for (int i = 0; i < a.size(); i++)
    if (maxi == -1 or a[i] > maxi)
      maxi = a[i];
  return maxi;
}

void sumcal(int node, vector<vector<int>> &data, vector<int> &limit) {
  if (node == 0) {
    // cout << "currently inserting the costs of the starting node "<<endl;
    for (int i = 1; i <= 2; i++)
      data[node].push_back(0);
  } else {
    // cout << "calculating cost of  "<< node <<endl;
    vector<int> t;
    t.push_back(mod(1 - 1) + data[node - 1][0]);
    t.push_back(mod(1 - limit[node - 1]) + data[node - 1][1]);
    data[node][0] = maximum(t);
    vector<int> t1;
    t1.push_back(mod(limit[node] - 1) + data[node - 1][0]);
    t1.push_back(mod(limit[node] - limit[node - 1]) + data[node - 1][1]);
    data[node][1] = maximum(t1);
  }
  if (node < nodes - 1)
    return sumcal(node + 1, data, limit);
  if (node == nodes - 1)
    return;
  // cout <<" control never enters here "<<endl;
  return;
}

int main(int argc, char const *argv[]) {
  int t;
  // cout << "enter the number of test cases " <<endl;
  cin >> t;
  while (t-- > 0) {
    // cout <<" enter the number of nodes "<<endl;
    cin >> nodes;
    vector<int> limit(nodes);
    // cout <<" enter the values "<<endl;
    for (int i = 0; i < nodes; i++)
      cin >> limit[i];
    // cout << "starting the call to the main calculation function "<<endl;
    vector<vector<int>> data(nodes, vector<int>(2));
    sumcal(0, data, limit);
    // cout << " completed calculating the distances "<<endl;
    int maxi = maximum(data[nodes - 1]);
    // cout << " the maximum distance is " ;
    cout << maxi;
    if (t > 0)
      cout << endl;
  }
  return 0;
}
