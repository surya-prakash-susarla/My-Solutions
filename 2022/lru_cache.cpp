#include <bits/stdc++.h>
using namespace std;

class LRUCache {
 public:
  LRUCache(int capacity) { maxvalue = capacity; }

  int get(int key) {
    auto it = values.find(key);
    if (it == values.end()) {
      return -1;
    } else {
      counter++;
      it->second.second = counter;
      times.push({key, counter});
      return it->second.first;
    }
  }

  void put(int key, int value) {
    auto it = values.find(key);
    if (it == values.end()) {
      if (values.size() == maxvalue) {
        while (values[times.front().first].second != times.front().second)
          times.pop();

        values.erase(times.front().first);
        times.pop();

        counter++;
        values[key] = {value, counter};
        times.push({key, counter});

      } else {
        counter++;
        values[key] = {value, counter};
        times.push({key, counter});
      }
    } else {
      counter++;
      it->second.first = value;
      it->second.second = counter;
      times.push({key, counter});
    }
  }

  int maxvalue;
  int counter = 0;
  typedef pair<int, int> pint;
  unordered_map<int, pint> values;
  queue<pint> times;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
  return 0;
}
