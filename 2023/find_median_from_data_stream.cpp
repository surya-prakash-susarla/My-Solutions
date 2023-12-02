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

class MedianFinder {
 public:
  map<int, int> values;
  int n = 0;

  MedianFinder() {}

  void addNum(int num) {
    values[num]++;
    n++;
  }

  pair<int, int> getValue(int pos1, int pos2) {
    pos1++;
    pos2++;
    int c1 = pos1;
    int c2 = pos2;
    pair<int, int> answer;
    for (auto i : values) {
      if (i.second >= c1) {
        answer.first = i.first;
        c1 = INT_MAX;
      }
      if (i.second >= c2) {
        answer.second = i.first;
        break;
      }
      c1 -= i.second;
      c2 -= i.second;
    }
    return answer;
  }

  int getValue(int pos) {
    pos++;
    int current = pos;
    for (auto i : values)
      if (i.second >= current)
        return i.first;
      else
        current -= i.second;
    return -1;
  }

  double findMedian() {
    if (n % 2 == 0) {
      const pair<int, int> temp = getValue((n / 2) - 1, (n / 2));
      return (double)(temp.first + temp.second) / 2;
    } else {
      return getValue(n / 2);
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
