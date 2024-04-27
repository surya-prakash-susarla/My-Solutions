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

class LRUCache {
 public:
  LRUCache(int capacity) { max_cap = capacity; }

  int get(int key) {
    auto it = actual_values.find(key);
    if (it == actual_values.end()) {
      return -1;
    } else {
      t++;
      current_use[key] = t;
      usage.push(make_pair(t, key));
      return it->second;
    }
  }

  void put(int key, int value) {
    t++;

    auto it = actual_values.find(key);
    if (it != actual_values.end()) {
      actual_values[key] = value;
      current_use[key] = t;
      usage.push(make_pair(t, key));
      return;
    }

    if (actual_values.size() < max_cap) {
      actual_values[key] = value;
      current_use[key] = t;
      usage.push(make_pair(t, key));
    } else {
      while (actual_values.size() == max_cap) {
        pair<int, int> lru = usage.top();
        usage.pop();
        if (lru.first != current_use[lru.second])
          continue;
        actual_values.erase(lru.second);
      }
      current_use[key] = t;
      actual_values[key] = value;
      usage.push(make_pair(t, key));
    }
  }

  map<int, int> actual_values;
  map<int, int> current_use;
  priority_queue<pair<int, int>,
                 vector<pair<int, int>>,
                 greater<pair<int, int>>>
      usage;

  int t = 0;
  int max_cap = 0;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
