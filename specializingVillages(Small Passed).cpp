#include <iostream>
#include <limits>
#include <vector>

using namespace std;
typedef long long int llint;

llint max_value = numeric_limits<llint>::max();

void print(vector<vector<llint>> edges) {
  cout << "printing the data of the edges " << endl;
  for (llint i = 0; i < edges.size(); i++) {
    for (llint j = 0; j < edges.size(); j++)
      cout << edges[i][j] << " ";
    cout << endl;
  }
  return;
}

void getCombination(llint index,
                    vector<bool> fruit,
                    vector<llint>& values,
                    vector<vector<llint>>& edges) {
  if (index == edges.size() - 1) {
    llint count = 0;
    for (llint i = 0; i < edges.size(); i++) {
      llint nearest = max_value;
      for (llint j = 0; j < edges.size(); j++) {
        if (edges[i][j] != max_value and fruit[j] != fruit[i] and
            edges[i][j] < nearest)
          nearest = edges[i][j];
      }
      if (nearest != max_value)
        count += nearest;
      else
        return;
    }
    values.push_back(count);
    return;
  }
  fruit[index] = false;
  getCombination(index + 1, fruit, values, edges);
  fruit[index] = true;
  getCombination(index + 1, fruit, values, edges);
  return;
}

void all_pairs(vector<vector<llint>>& edges) {
  llint nodes = edges.size();
  // cout << "Before shortest path " << endl;
  // print(edges);
  // cout << endl;
  for (llint i = 0; i < nodes; i++) {
    for (llint j = i; j < nodes; j++) {
      if (i == j) {
        edges[i][j] = 0;
        continue;
      }
      for (llint k = 0; k < nodes; k++)
        if (edges[i][k] != max_value and edges[k][j] != max_value and
            edges[i][j] > edges[i][k] + edges[k][j])
          edges[i][j] = edges[i][k] + edges[k][j],
          edges[j][i] = edges[i][k] + edges[k][j];
    }
  }
  // cout << "After shortest path " << endl;
  // print(edges);
  // cout << endl;
  return;
}

llint calc() {
  llint v, e;
  cin >> v >> e;
  vector<vector<llint>> edges(v, vector<llint>(v, max_value));
  for (llint i = 0; i < e; i++) {
    llint a, b, l;
    cin >> a >> b >> l;
    edges[a - 1][b - 1] = l;
    edges[b - 1][a - 1] = l;
  }
  all_pairs(edges);
  vector<llint> values(edges.size(), max_value);
  getCombination(0, vector<bool>(edges.size(), false), values, edges);
  llint count = 1, min_value = values[0];
  for (llint i = 1; i < values.size(); i++)
    if (values[i] < min_value) {
      min_value = values[i];
      count = 1;
    } else if (values[i] == min_value)
      count++;
  return count * 2;
}

int main() {
  llint t;
  cin >> t;
  for (llint k = 1; k <= t; k++) {
    llint answer = calc();
    cout << "Case #" << k << ": " << answer << endl;
  }
  return 0;
}