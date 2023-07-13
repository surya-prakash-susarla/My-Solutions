#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  typedef ListNode node;
  typedef pair<node*, node*> pnodes;

  pnodes reverse(pnodes limits) {
    node* head = limits.first;
    node* next = limits.first->next;

    while (head != limits.second) {
      node* temp = next->next;
      next->next = head;
      head = next;
      next = temp;
    }

    return {head, limits.first};
  }

  pair<pnodes, bool> getRange(node* head, int k) {
    pnodes answer{head, head};
    k--;
    head = head ? head->next : nullptr;
    while (head and k) {
      answer.second = head;
      head = head->next;
      k--;
    }
    return {answer, answer.first and k == 0};
  }

  node* __rec__(node* head, int k) {
    pair<pnodes, bool> limits = getRange(head, k);
    if (limits.second) {
      // perfect grouping
      node* next_group = __rec__(limits.first.second->next, k);
      pnodes current_limits =
          reverse({limits.first.first, limits.first.second});
      current_limits.second->next = next_group;
      return current_limits.first;
    } else {
      // short on count so no reversing
      return limits.first.first;
    }
  }

  ListNode* reverseKGroup(ListNode* head, int k) { return __rec__(head, k); }
};