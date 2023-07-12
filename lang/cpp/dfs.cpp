#include <iostream>
#include <vector>
using namespace std;

int clib, croad;

void depth(int **paths, int edges, int node, vector<bool> &covered) {
  // // cout<<"in depth function for node "<<node <<endl;
  for (int i = 0; i < edges; i++) {
    if (paths[i][0] == node and not covered[paths[i][1]]) {
      covered[paths[i][1]] = true;
      depth(paths, edges, paths[i][1], covered);
    } else if (paths[i][1] == node and not covered[paths[i][0]]) {
      covered[paths[i][0]] = true;
      depth(paths, edges, paths[i][0], covered);
    }
  }
}

vector<vector<int>> find_all_depths(int n, int **paths, int edges) {
  vector<vector<int>> cons(n);
  for (int i = 0; i < n; i++) {
    vector<bool> cov(n, false);
    cov[i] = true;
    //// cout<<"calling depth function for node "<<i<<endl;
    depth(paths, edges, i, cov);
    //// cout<<"completed calculating depth"<<endl;
    for (int j = 0; j < cov.size(); j++) {
      if (cov[j] and j != i) {
        //  // cout<<"included node "<<j<<endl;
        cons[i].push_back(j);
        //  // cout<<"after inclusion"<<endl;
      }
    }
  }
  return cons;
}

void high_cost(vector<vector<int>> cons, vector<bool> &covered, int &c) {
  // cout<<"in high cost function"<<endl;
  int max = -1, maxind = -1;
  for (int i = 0; i < cons.size(); i++) {
    if (not covered[i] and (max == -1 or (cons[i].size() > max))) {
      max = cons[i].size();
      maxind = i;
    }
  }
  // cout<<"selected node "<<maxind<<" with depth "<<max<<endl;
  if (maxind == -1)
    return;
  covered[maxind] = true;
  // cout<<"contents of cons are "<<endl;
  // for(int i=0;i<cons[maxind].size();i++)
  // cout<<cons[maxind][i]<<endl;
  // cout<<"clib = "<<clib<< " croad= "<<croad <<endl;
  c = c + clib;
  c = c + cons[maxind].size() * croad;
  // cout<<"cost at node "<<maxind<< " is "<<c<<endl;
  for (int i = 0; i < cons[maxind].size(); i++)
    covered[cons[maxind][i]] = true;
  // cout<<"contents of covered matrix starting from "<<maxind <<" are :
  // "<<endl;
  for (int i = 0; i < covered.size(); i++)
    // cout<<(bool)covered[i]<<endl;
    return;
}

int cost(vector<vector<int>> cons) {
  // cout<<"in cost function"<<endl;
  vector<bool> covered(cons.size(), false);
  int c = 0;
  vector<bool> all_covered(cons.size(), true);
  while (covered != all_covered) {
    high_cost(cons, covered, c);
  }
  return c;
}

int main() {
  int q;
  // cout<<"enter the number of queries "<<endl;
  cin >> q;
  while (q-- > 0) {
    int nodes, edges;
    // cout<<"enter the number of nodes and edges"<<endl;
    cin >> nodes >> edges;
    // cout<<"enter the costs of clib and croad "<<endl;
    cin >> clib >> croad;
    // cout<<"enter the edges"<<endl;
    int **path;
    path = new int *[edges];
    for (int i = 0; i < edges; i++) {
      path[i] = new int[2];
      int a, b;
      cin >> a >> b;
      path[i][0] = a - 1;
      path[i][1] = b - 1;
    }
    if (clib < croad)
      cout << nodes * clib;
    else {
      // cout<<"cost of clib = "<<clib<< " croad = "<<croad<<endl;
      // cout<<"starting depth search "<<endl;
      cout << cost(find_all_depths(nodes, path, edges));
    }
    if (q > 0)
      cout << endl;
    delete path;
  }
  // cout<<endl<<endl<<"program complete"<<endl;
  return 0;
}
