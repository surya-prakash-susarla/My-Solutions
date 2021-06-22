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

  ListNode* detectCycle(ListNode* head) {
    unordered_map<node*, bool> use;

    if (head == nullptr)
      return head;

    while (true) {
      if (use[head])
        return head;
      use[head] = true;
      head = head->next;
      if (head == nullptr)
        return nullptr;
    }
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
