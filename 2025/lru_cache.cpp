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
  int limit;
  unordered_map<int, int> contents;
  unordered_map<int, int> usage;
  priority_queue<pair<int, int>,
                 vector<pair<int, int>>,
                 greater<pair<int, int>>>
      use_order;
  int time = 0;

  LRUCache(int capacity) { limit = capacity; }

  int get(int key) {
    auto it = contents.find(key);
    if (it != contents.end()) {
      time++;
      // cout << "key : " << key << " found , value : " << it->second << endl;
      usage[key] = time;
      use_order.push(make_pair(time, key));
      return it->second;
    }
    // cout << "key not found, returning" << endl;
    return -1;
  }

  void put(int key, int value) {
    time++;
    if (contents.contains(key)) {
      contents[key] = value;
      usage[key] = time;
      // cout << "key exists, updating usage to : " << usage[key] << endl;
      use_order.push(make_pair(time, key));
    } else {
      // cout << "inserting key " << key << endl;
      if (contents.size() >= limit) {
        int key_to_delete = find_lru_key();
        // cout << "over the limit , removing : " << key_to_delete << endl;
        contents.erase(key_to_delete);
        usage.erase(key_to_delete);
      }
      contents[key] = value;
      usage[key] = time;
      use_order.push(make_pair(time, key));
    }
  }

  int find_lru_key() {
    while (not use_order.empty()) {
      pair<int, int> current = use_order.top();
      use_order.pop();
      if (usage[current.second] == current.first) {
        return current.second;
      }
    }

    // cout << "ERROR: NO VALID USAGE RECORD FOUND FOR DELETION" << endl;
    return -1;
  }
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
