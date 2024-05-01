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
  MedianFinder() {}

  void addNum(int num) {
    total++;
    counts[num]++;
  }

  map<int, int>::iterator findval(int& loc) {
    for (auto it = counts.begin(); it != counts.end(); it++) {
      if (it->second < loc) {
        loc -= it->second;
      } else {
        return it;
      }
    }
    cout << "SOMETHING WRONG" << endl;
    return counts.end();
  }

  double findMedian() {
    int req = (total / 2) + 1;
    if (total % 2) {
      return findval(req)->first;
    } else {
      req--;
      auto first = findval(req);
      int second = (req < first->second) ? first->first : next(first)->first;
      return (double)(first->first + second) / 2;
    }
  }

  int total = 0;
  map<int, int> counts;
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
