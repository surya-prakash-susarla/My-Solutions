#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (llint i = 0; i < n; i++)
#define llint long long int

llint nodes, edges;
llint **paths;

llint cost_cal(llint start, llint end, llint cost, vector<bool> &covered) {
  // cout<<"currently in node "<<start<<" with cost "<<cost<<endl;
  if (start == end) {
    // cout<<"returning cost "<<endl;
    return cost;
  }
  covered[start] = true;
  llint min = -1;
  rep(i, nodes) {
    if (paths[start][i] != -1 and not covered[i]) {
      llint a = cost_cal(i, end, (cost | paths[start][i]), covered);
      if (min == -1 or (min != -1 and a < min))
        min = a;
    }
  }
  // cout<<"returning from sub "<<min<<endl;
  return min;
}

int main() {
  // cout<<"enter the number of nodes and edges"<<endl;
  cin >> nodes >> edges;
  paths = new llint *[nodes];
  rep(i, nodes) {
    paths[i] = new llint[nodes];
    rep(j, nodes) paths[i][j] = -1;
  }
  // cout<<"enter the edges "<<endl;
  rep(i, edges) {
    llint a, b, l;
    cin >> a >> b >> l;
    a -= 1;
    b -= 1;
    if (a == b)
      continue;
    if (paths[a][b] == -1 or (paths[a][b] != -1 and l < paths[a][b])) {
      paths[a][b] = l;
      //  paths[b][a]=l;
    }
  }
  // cout<<"enter the starting and ending nodes"<<endl;
  llint start, end;
  cin >> start >> end;
  // cout<<"the cost is ";
  vector<bool> cov(nodes, false);
  cout << cost_cal(start - 1, end - 1, 0, cov);
  return 0;
}
