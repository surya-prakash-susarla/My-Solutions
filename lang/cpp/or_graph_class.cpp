#include <iostream>
#include <vector>
using namespace std;

#define pb push_back
#define rep(i, n) for (int i = 0; i < n; i++)

class node {
public:
  int num;
  vector<int> cons;
  vector<int> dists;
};

node *graph;
//////
void cost_finder(int start, int end, int current_cost, int &prev_cost,
                 vector<bool> covered) {
  cout << "starting from " << start << " with distance " << current_cost
       << " and previous cost " << prev_cost << endl;
  if (start == end) {
    cout << "reached end point" << endl;
    if ((prev_cost != -1 and current_cost < prev_cost) or prev_cost == -1) {
      cout << "updating lowest cost " << prev_cost << endl;
      prev_cost = current_cost;
    }
    return;
  }
  covered[start] = true;
  if (prev_cost != -1 and current_cost >= prev_cost) {
    cout << "returning -1 since current_cost > prev_cost " << current_cost
         << " prev_cost " << prev_cost << endl;
    return;
  }
  int min = -1;
  if (prev_cost == -1 or current_cost < prev_cost) {
    cout << "continuing since prev_cost = " << prev_cost << " current cost is "
         << current_cost << endl;
    rep(i, graph[start].cons.size()) {
      if (not covered[graph[start].cons[i]]) {
        int new_cost = current_cost | graph[start].dists[i];
        cout << "new cost is " << new_cost << " starting at " << start
             << " via " << graph[start].cons[i] << endl;
        cost_finder(graph[start].cons[i], end, new_cost, prev_cost, covered);
      }
      cout << "\n\n\n checking for further nodes from " << start << endl;
    }
  }
  return;
}
/////

int main() {
  int nodes, edges;
  cout << "enter the number of nodes and edges" << endl;
  cin >> nodes >> edges;
  graph = new node[nodes];
  rep(i, nodes) graph[i].num = i;
  cout << "enter the edges" << endl;
  rep(i, edges) {
    int a, b, c;
    cin >> a >> b >> c;
    a -= 1;
    b -= 1;
    graph[a].cons.pb(b);
    graph[b].cons.pb(a);
    graph[a].dists.pb(c);
    graph[b].dists.pb(c);
  }
  cout << "enter the starting and ending points of the path " << endl;
  int start, end;
  cin >> start >> end;
  start -= 1;
  end -= 1;
  cout << "starting the calculation of the cost " << endl;
  int prev = -1;
  cost_finder(start, end, 0, prev, vector<bool>(nodes, false));
  cout << "prev_cost = " << prev << endl;
  cout << "completed printing the final result" << endl;
  return 0;
}
