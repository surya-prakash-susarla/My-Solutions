#include <bits/stdc++.h>

using namespace std;

struct ListNode;
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
  ListNode* swapPairs(ListNode* head) {
    typedef ListNode node;

    if (head == nullptr)
      return nullptr;

    node* root = nullptr;

    node* first = head;
    node* second = first->next;
    node* parent = nullptr;

    while (second != nullptr) {
      node* temp = second->next;
      second->next = first;
      first->next = temp;

      if (parent) {
        parent->next = second;
      }
      parent = first;

      if (root == nullptr)
        root = second;

      first = first->next;
      second = first ? first->next : nullptr;
    }

    return root ? root : head;
  }
};