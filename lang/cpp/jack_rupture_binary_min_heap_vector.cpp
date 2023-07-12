#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;
typedef long long int llint;
#define INF numeric_limits<llint>::max()

llint n, e;
vector<vector<pair<llint, llint>>> connections;

class compare {
public:
  int operator()(const pair<llint, llint> &a, const pair<llint, llint> &b) {
    return a.first > b.first;
  }
};

#define pair_queue                                                             \
  priority_queue<pair<llint, llint>, vector<pair<llint, llint>>, compare>

pair_queue main_queue;

// changing function modes
vector<llint> current_values;

void update_weight(llint weight, llint destination) {
  if (current_values[destination] > weight) {
    current_values[destination] = weight;
    main_queue.push(make_pair(weight, destination));
  }
  return;
}

pair<llint, llint> get_lowest() {
  while (not main_queue.empty()) {
    pair<llint, llint> lowest = main_queue.top();
    if (current_values[lowest.second] == lowest.first)
      return lowest;
    else
      main_queue.pop();
  }
  return make_pair(INF, INF);
}

llint find_way() {
  // cout << endl << "STARTING THE SEARCH" << endl;
  while (true and not main_queue.empty()) {
    pair<llint, llint> lowest = get_lowest();
    // cout << "VERTEX :  " << lowest.second << endl;
    // cout << "LENGTH : " << lowest.first << endl;
    if (lowest == make_pair(INF, INF))
      return INF;
    if (lowest.second == n - 1)
      return lowest.first;
    main_queue.pop();
    for (pair<llint, llint> t : connections[lowest.second])
      update_weight(max(t.second, lowest.first), t.first);
  }
  return INF;
}

int main() {
  cin >> n >> e;
  connections.resize(n);
  current_values.resize(n, INF);
  for (int i = 0; i < e; i++) {
    llint a, b, c;
    cin >> a >> b >> c;
    connections[a - 1].push_back(make_pair(b - 1, c));
    connections[b - 1].push_back(make_pair(a - 1, c));
  }
  for (int i = 0; i < n; i++)
    main_queue.push(make_pair(INF, i));

  update_weight(0, 0);
  llint final_answer = find_way();
  if (final_answer == INF)
    cout << "NO PATH EXISTS";
  else
    cout << final_answer;
  return 0;
}