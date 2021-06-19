#include <iostream>
#include <vector>
using namespace std;

class node {
public:
  vector<int> limits;
};

int n, m;
vector<int> node_values;
vector<node> nodes;

int ways(int index) {
  if (index < 0)
    return 1;
  int limits = 9;
  for (int i : nodes[index].limits)
    if (node_values[i] < limits)
      limits = node_values[i];
  int total_ways = 0;
  for (int i = limits; i >= 0; i--) {
    node_values[index] = i;
    total_ways += ways(index - 1);
  }
  return total_ways;
}

int main() {
  cin >> n >> m;
  node_values.resize(n);
  nodes.resize(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    nodes[a].limits.push_back(b);
  }
  cout << ways(n - 1) << endl;
  return 0;
}
