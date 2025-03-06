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

class MyCircularQueue {
 public:
  list<int> values;
  int k;

  MyCircularQueue(int k) { this->k = k; }

  bool enQueue(int value) {
    if (values.size() < k) {
      values.push_back(value);
      return true;
    } else {
      return false;
    }
  }

  bool deQueue() {
    if (not values.empty()) {
      values.pop_front();
      return true;
    } else {
      return false;
    }
  }

  int Front() { return not values.empty() ? values.front() : -1; }

  int Rear() { return not values.empty() ? values.back() : -1; }

  bool isEmpty() { return values.empty(); }

  bool isFull() { return values.size() == k; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
