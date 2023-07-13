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
  ListNode* detectCycle(ListNode* orig) {
    if (orig == nullptr)
      return nullptr;

    ListNode* head = orig;
    ListNode* temp = head;
    head = head->next;
    if (head)
      head = head->next;

    while (head) {
      if (temp == head)
        break;
      head = head->next;
      if (head)
        head = head->next;
      temp = temp->next;
    }

    if (head == nullptr)
      return nullptr;

    int size = 1;
    head = head->next;
    while (head != temp) {
      size++;
      head = head->next;
    }

    head = orig;
    temp = orig;

    while (size-- > 0)
      head = head->next;

    while (temp != head) {
      temp = temp->next;
      head = head->next;
    }

    return temp;
  }
};
