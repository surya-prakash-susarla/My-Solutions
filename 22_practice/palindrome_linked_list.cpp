#include <bits/stdc++.h>

using namespace std;

/* Test Cases
[1,2,2,1]
[1,2]
[1,2,3,4,5]
[1]
[2,2,2]
*/

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
  using node = ListNode;

  bool isPalindrome(node* orig) {
    if (orig == nullptr)
      return false;

    node* head = orig;
    node* tail = orig;

    while (head) {
      tail = tail->next;
      head = head->next;
      if (head)
        head = head->next;
    }

    stack<int> values;
    node* tb = tail;
    node* temp = tail;

    while (tail) {
      values.push(tail->val);
      tail = tail->next;
    }

    temp = orig;
    while (temp != tb) {
      if (values.empty())
        return true;
      if (temp->val != values.top())
        return false;
      values.pop();
      temp = temp->next;
    }

    return true;
  }
};
