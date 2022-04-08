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
  ListNode* middleNode(ListNode* orig) {
    ListNode* head = orig;
    ListNode* temp = orig;

    while (head and head->next) {
      head = head->next->next;
      temp = temp->next;
    }

    return temp;
  }
};
