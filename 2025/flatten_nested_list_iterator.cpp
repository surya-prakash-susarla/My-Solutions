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
  typedef NestedInteger nested_integer;
  typedef NestedIterator nested_iterator;

  int main_index = -1;
  NestedIterator* sub = nullptr;

  vector<nested_integer> input;

  NestedIterator(vector<NestedInteger>& input) {
    this->input = input;
    move_it();
  }

  void move_it() {
    if (sub and sub->hasNext()) {
      return;
    } else {
      sub = nullptr;
    }

    bool valid_ind_found = false;
    while (not valid_ind_found) {
      main_index++;
      if (main_index == input.size()) {
        break;
      }
      if (input[main_index].isInteger()) {
        valid_ind_found = true;
      } else {
        sub = new nested_iterator(input[main_index].getList());
        if (sub->hasNext()) {
          valid_ind_found = true;
        } else {
          sub = nullptr;
        }
      }
    }
  }

  int next() {
    if (sub) {
      int return_value = sub->next();
      if (not sub->hasNext()) {
        move_it();
      }
      return return_value;
    } else {
      const int return_value = input[main_index].getInteger();
      move_it();
      return return_value;
    }
  }

  bool hasNext() {
    if (sub)
      return (sub->hasNext());
    else
      return (main_index < input.size());
  }
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
