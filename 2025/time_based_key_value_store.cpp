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

class TimeMap {
 public:
  TimeMap() {}

  unordered_map<string, map<int, string>> store;

  void set(string key, string value, int timestamp) {
    store[key][timestamp] = value;
  }

  string get(string key, int timestamp) {
    auto store_it = store.find(key);
    if (store_it == store.end())
      return "";

    auto it = store_it->second.lower_bound(timestamp);
    if (it->first == timestamp)
      return it->second;

    if (it == store_it->second.begin())
      return "";

    return prev(it)->second;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
