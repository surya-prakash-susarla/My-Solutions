#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define INF ((unsigned)~0)

typedef long long int llint;

llint n, e;
vector<vector<llint>> table;

llint minimum_finder(vector<llint> input) {
  llint mini_value = INF;
  for (llint i : input)
    if (mini_value > i)
      mini_value = i;
  return mini_value;
}

llint calculate_length(llint location, vector<bool> covered,
                       llint current_cost) {

  if (location == n - 1)
    return current_cost;

  vector<llint> cost_values;
  for (llint i = 0; i < n; i++)
    if (not covered[i] and table[location][i] != -1) {
      vector<bool> temp_covered(covered);
      temp_covered[i] = true;
      llint temp_cost = current_cost;
      temp_cost + (table[location][i] - current_cost) < current_cost
          ? temp_cost = current_cost
          : temp_cost = current_cost + (table[location][i] - current_cost);
      cost_values.push_back(calculate_length(i, temp_covered, temp_cost));
    }

  return minimum_finder(cost_values);
}

llint find_ways(int location, vector<bool> covered) {
  // alternative to the same solution using DP
}

int main() {
  cin >> n >> e;
  vector<vector<llint>> temp(n, vector<llint>(n, -1));
  for (llint i = 0; i < e; i++) {
    llint a, b, c;
    cin >> a >> b >> c;
    temp[a - 1][b - 1] = c;
    temp[b - 1][a - 1] = c;
  }
  table = temp;
  llint final_answer = calculate_length(0, vector<bool>(n, false), 0);
  final_answer != -1 and final_answer != INF ? cout << final_answer
                                             : cout << "NO PATH EXISTS";
  return 0;
}
