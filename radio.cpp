#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef long long int llint;

llint n, k;
vector<llint> locations;

// temp function
void set_printer(set<llint> values) {
  for (set<llint>::iterator it = values.begin(); it != values.end(); it++)
    cout << *it << endl;
  return;
}

int find_radios(int index, vector<llint> &parent,
                vector<pair<llint, llint>> &boundaries) {
  if (index < 0) {
    set<llint> distinct_values;
    for (int i = 0; i < parent.size(); i++) {
      // cout<<"the value of parent is "<<parent[i]<<endl;
      distinct_values.insert(parent[i]);
    }
    // cout<<"the values in the set are "<<endl;
    // set_printer(distinct_values);
    return distinct_values.size();
  }
  pair<int, int> temp_pair =
      make_pair(locations[index] - k, locations[index] + k);
  if (index == locations.size() - 1) {
    parent[index] = locations[index];
    pair<int, int> temp_pair =
        make_pair(locations[index] - k, locations[index] + k);
  } else {
    if (temp_pair.second >= boundaries[index + 1].first) {
      temp_pair.first = boundaries[index + 1].first;
      temp_pair.second = boundaries[index + 1].first;
      parent[index] = parent[index + 1];
    } else {
      parent[index] = locations[index];
    }
  }
  boundaries[index] = temp_pair;

  // temp line
  // cout<<"the index is "<<index<<"			the parent is " <<
  // parent[index]<<endl;

  return find_radios(index - 1, parent, boundaries);
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    locations.push_back(temp);
  }
  sort(locations.begin(), locations.end());

  vector<pair<llint, llint>> boundaries(n, pair<int, int>(-1, -1));
  vector<llint> parent(n, -1);

  llint value = find_radios(n - 1, parent, boundaries);
  // cout<<"the minimum required value is " << value << endl;
  cout << value << endl;
  return 0;
}
