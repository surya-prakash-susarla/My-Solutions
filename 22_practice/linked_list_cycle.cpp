#include <bits/stdc++.h>

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
  bool hasCycle(ListNode* head) {
    if (head == nullptr)
      return false;

    ListNode* temp = head;
    head = head->next;
    if (head)
      head = head->next;

    while (head != nullptr) {
      if (temp == head)
        return true;

      head = head->next;
      if (head)
        head = head->next;
      temp = temp->next;
    }

    return false;
  }
};
