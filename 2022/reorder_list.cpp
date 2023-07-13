#include <bits/stdc++.h>

using namespace std;

/* Test Cases
[1,2,3,4]
[1,2,3,4,5]
[1,2]
[1,2,3]
[1,2,3,4,5,6,7,8,9,10]
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
  void reorderList(ListNode* orig) {
    using node = ListNode;

    node* head = orig;
    node* tail = orig;

    while (head) {
      tail = tail->next;
      head = head->next;
      if (head)
        head = head->next;
    }

    stack<node*> b;
    node* temp = tail;
    while (temp) {
      b.push(temp);
      temp = temp->next;
    }

    temp = orig;
    node* temp2 = orig;

    while (temp != tail) {
      temp = temp->next;
      if (not b.empty()) {
        temp2->next = b.top();
        b.pop();
        temp2 = temp2->next;
        temp2->next = temp;
      } else if (temp == tail) {
        break;
      }
      temp2 = temp2->next;
    }
    temp2->next = nullptr;
  }
};
