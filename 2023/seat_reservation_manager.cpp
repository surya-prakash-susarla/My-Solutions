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

class SeatManager {
 public:
  SeatManager(int n) {}

  int reserve() {
    if (not prev_seats.empty()) {
      int top = prev_seats.top();
      prev_seats.pop();
      return top;
    }
    return auto_index++;
  }

  void unreserve(int value) { prev_seats.push(value); }

  int auto_index = 1;
  priority_queue<int, vector<int>, greater<int>> prev_seats;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
