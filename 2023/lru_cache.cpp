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
  typedef pair<int, int> pint;
  LRUCache(int capacity) { cap = capacity; }

  int get(int key) {
    auto it = values.find(key);
    if (it == values.end())
      return -1;

    usage[key] = time;
    rec.push(make_pair(time++, key));
    return it->second;
  }

  void put(int key, int value) {
    auto it = values.find(key);
    if (it != values.end()) {
      values[key] = value;
      usage[key] = time;
      rec.push(make_pair(time++, key));
    } else {
      if (values.size() == cap) {
        while (true) {
          const pint i = rec.top();
          rec.pop();
          if (i.first == usage[i.second]) {
            values.erase(i.second);
            usage.erase(i.second);
            break;
          }
        }
        values[key] = value;
        usage[key] = time;
        rec.push(make_pair(time++, key));
      } else {
        values[key] = value;
        usage[key] = time;
        rec.push(make_pair(time++, key));
      }
    }
  }

  int time = 1;
  map<int, int> values;
  map<int, int> usage;
  priority_queue<pint, vector<pint>, greater<pint>> rec;
  int cap;
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
