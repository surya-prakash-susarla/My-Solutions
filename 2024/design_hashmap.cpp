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

class MyHashMap {
 public:
  MyHashMap() {}

  void put(int key, int value) {
    list<pair<int, int>>::iterator it = get_it(key);
    if (it != values.end()) {
      it->second = value;
    } else {
      values.push_back({key, value});
    }
  }

  list<pair<int, int>>::iterator get_it(int key) {
    for (auto it = values.begin(); it != values.end(); it++)
      if (it->first == key)
        return it;
    return values.end();
  }

  int get(int key) {
    list<pair<int, int>>::iterator it = get_it(key);
    return it != values.end() ? it->second : -1;
  }

  void remove(int key) {
    list<pair<int, int>>::iterator it = get_it(key);
    if (it != values.end())
      values.erase(it);
  }

  list<pair<int, int>> values;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
