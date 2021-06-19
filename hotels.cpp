#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

#define highest 100000

using namespace std;

void set_printer(set<int> values) {
  for (set<int>::iterator it = values.begin(); it != values.end(); it++)
    cout << *it << endl;
  return;
}

int n, k;
vector<int> locations;
vector<pair<int, int>> boundaries;
vector<int> parents;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    locations.push_back(temp);
  }
  cin >> k;
  sort(locations.begin(), locations.end());
  vector<int> temp_parents(n, highest);
  parents = temp_parents;
  pair<int, int> temp_pair;
  temp_pair.first = highest;
  temp_pair.second = highest;
  vector<pair<int, int>> temp_boundaries(n, temp_pair);
  boundaries = temp_boundaries;
  bool last = true;
  for (int i = locations.size() - 1; i > -1; i--) {
    if (last) {
      boundaries[i] = make_pair(locations[i] - k, locations[i] + k);
      parents[i] = locations[i];
      last = false;
    } else {
      int upper_boundary = locations[i] + k;
      if (upper_boundary >= boundaries[i + 1].first) {
        int intersection =
            upper_boundary - (upper_boundary - boundaries[i + 1].first);
        cout << "the intersection point for " << locations[i] << " is "
             << intersection << endl;
        pair<int, int> temp = make_pair(intersection, intersection);
        boundaries[i] = temp;
        parents[i] = parents[i + 1];
      } else {
        boundaries[i] = make_pair(locations[i] - k, locations[i] + k);
        parents[i] = locations[i];
      }
    }
  }
  set<int> final_values;
  for (int i = 0; i < parents.size(); i++) {
    cout << "values = " << parents[i] << endl;
    final_values.insert(parents[i]);
  }
  // set_printer ( final_values );
  cout << "the minimum requirement is " << final_values.size() << endl;
  return 0;
}