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

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
 public:
  NestedIterator(vector<NestedInteger>& nestedList) {
    values = nestedList;
    pos = -1;
    it = nullptr;
    move();
  }

  void move() {
    if (it) {
      if (not it->hasNext()) {
        delete it;
        it = nullptr;
        move();
      }
      return;
    }
    pos++;
    if (pos < values.size() and not values[pos].isInteger()) {
      it = new NestedIterator(values[pos].getList());
      if (not it->hasNext())
        move();
    }
  }

  int next() {
    int value;
    if (it) {
      value = it->next();
    } else {
      value = values[pos].getInteger();
    }
    move();
    return value;
  }

  bool hasNext() {
    if (it)
      return it->hasNext();
    else
      return pos < values.size();
  }

  vector<NestedInteger> values;
  int pos;
  NestedIterator* it;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
