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
  SnapshotArray(int length) {
    // nothing needed.
  }

  void set(int index, int val) {
    vpint& ref = snaps[index];
    if (not ref.empty() and ref.rbegin()->second == current_snap_id) {
      ref.rbegin()->first = val;
    } else {
      ref.push_back(make_pair(val, current_snap_id));
    }
  }

  int snap() {
    current_snap_id += 1;
    return current_snap_id - 1;
  }

  int get(int index, int snap_id) {
    vpint& ref = snaps[index];

    for (int i = ref.size() - 1; i > -1; i--) {
      if (ref[i].second > snap_id)
        continue;
      return ref[i].first;
    }

    return 0;
  }

  typedef pair<int, int> pint;
  typedef vector<pint> vpint;

  int current_snap_id = 0;
  map<int, vpint> snaps;
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
