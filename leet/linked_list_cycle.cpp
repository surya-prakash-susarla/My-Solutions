#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

// Problem:

typedef long long int llint;
typedef long double ldouble;

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  using node = ListNode;
  int minval = numeric_limits<int>::min();

  bool hasCycle(ListNode* head) {
    if (head == nullptr)
      return false;
    if (head->val == minval)
      return true;
    head->val = minval;
    return hasCycle(head->next);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
