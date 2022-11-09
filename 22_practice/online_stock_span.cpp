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

class StockSpanner {
 public:
  map<int, int> values;
  int count = 0;

  StockSpanner() { values[numeric_limits<int>::max()] = 0; }

  int next(int price) {
    count++;
    int answer = 0;
    for (auto it = values.upper_bound(price); it != values.end(); it++)
      answer = max(answer, it->second);
    values[price] = max(values[price], count);
    return count - answer;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
