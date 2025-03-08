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

class RandomizedSet {
 public:
  unordered_set<int> values;

  RandomizedSet() {}

  bool insert(int val) {
    if (values.contains(val))
      return false;
    values.insert(val);
    return true;
  }

  bool remove(int val) {
    if (values.contains(val)) {
      values.erase(val);
      return true;
    }
    return false;
  }

  int getRandom() {
    int ind = (rand() % values.size());
    return *(next(values.begin(), ind));
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
