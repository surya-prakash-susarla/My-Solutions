#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class node {
public:
  int last_affected_index;
  vector<int> limits;
  vector<int> memo;

  node() : memo(11, -1) {}
};

vector<node> nodes;
vector<int> node_values;

int m, n;

int ways(int index, int last_affected_index) {

  if (index < 0)
    return 1;

  int limits = 10;

  for (int i : nodes[index].limits)
    if (node_values[i] <= limits)
      limits = node_values[i];

  // cout << "Limit value at index : " << index << " is " << limits << endl;

  int total_ways = 0;
  bool first_iteration = false;

  for (int i = limits; i > 0; i--) {
    int return_value = 0;
    node_values[index] = i;
    node temp = nodes[index];
    int limiting_index = last_affected_index;
    if (first_iteration) {
      limiting_index =
          min(last_affected_index, nodes[index].last_affected_index);
      first_iteration = not first_iteration;
    } else {
      limiting_index = nodes[index].last_affected_index;
    }
    cout << "LIMITING INDEX FOR " << index << " is " << limiting_index << endl;
    if (temp.memo[i] != -1 and index <= limiting_index) {
      return_value = nodes[index].memo[i];
    } else {
      return_value = ways(index - 1, limiting_index);
      nodes[index].memo[i] = return_value;
    }
    total_ways += return_value;
  }

  return total_ways;
}

int main() {
  // cout<<"n and m "<<endl;
  cin >> n >> m;

  nodes.resize(n);
  node_values.resize(n);

  for (int i = 0; i < n; i++)
    nodes[i].last_affected_index = n + 1;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    nodes[a].limits.push_back(b);

    if (nodes[b].last_affected_index > a)
      nodes[b].last_affected_index = a;
  }

  // cout << " The final answer is " << ways ( n - 1 ) << endl ;

  cout << ways(n - 1, nodes[n - 1].last_affected_index);

  // cout << " Memo values are " << endl;

  return 0;
}
