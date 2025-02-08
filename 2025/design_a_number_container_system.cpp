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

class NumberContainers {
 public:
  NumberContainers() {}

  map<int, int> mapping;
  map<int, priority_queue<int, vector<int>, greater<int>>> locations;

  void change(int index, int number) {
    mapping[index] = number;
    locations[number].push(index);
  }

  int find(int number) {
    priority_queue<int, vector<int>, greater<int>>& ref = locations[number];
    while (not ref.empty()) {
      int top = ref.top();
      if (mapping[top] == number) {
        return top;
      } else {
        ref.pop();
      }
    }
    return -1;
  }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
