#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

typedef long long int llint;
typedef long long unsigned int ullint;

using namespace std;

class SnapshotArray {
 public:
  SnapshotArray(int length) { store = vector<map<int, int>>(length); }

  void set(int index, int val) { store[index][current_snap_id] = val; }

  int snap() { return ++current_snap_id; }

  int get(int index, int snap_id) {
    auto it = store[index].lower_bound(snap_id);
    if (it == store[index].end()) {
      return store[index].size() > 0 ? store[index].rbegin()->second : 0;
    } else {
      if (it == store[index].begin())
        return 0;
      it = prev(it);
      return it->second;
    }
  }

  int current_snap_id = -1;
  vector<map<int, int>> store;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
