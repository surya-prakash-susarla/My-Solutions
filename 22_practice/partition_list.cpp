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

  ListNode* partition(ListNode* orig, int x) {
    if (orig == nullptr)
      return nullptr;

    node* low = orig->val < x ? orig : nullptr;
    node* init_high = nullptr;
    node* high = nullptr;
    node* high_next = nullptr;
    node* start = orig;

    node* temp = orig;

    while (temp != nullptr) {
      if (temp->val >= x) {
        high = temp;
        init_high = temp;
        high_next = temp->next;
        break;
      }
      low = temp;
      temp = temp->next;
    }

    while (high_next != nullptr) {
      if (high_next->val < x) {
        if (low == nullptr) {
          low = high_next;
          high->next = high_next->next;
          low->next = init_high;
          high_next = high->next;
          start = low;
        } else {
          high->next = high_next->next;
          high_next->next = low->next;
          low->next = high_next;
          low = low->next;
          high_next = high->next;
        }
      } else {
        high = high_next;
        high_next = high_next->next;
      }
    }
    return start;
  }
};
