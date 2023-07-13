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

  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    node* left = list1;
    node* right = list2;

    if (left == nullptr)
      return right;
    if (right == nullptr)
      return left;

    node* root = nullptr;

    if (left->val <= right->val) {
      root = left;
      left = left->next;
    } else {
      root = right;
      right = right->next;
    }

    node* head = root;

    while (left and right) {
      if (left->val <= right->val) {
        head->next = left;
        left = left->next;
      } else {
        head->next = right;
        right = right->next;
      }
      head = head->next;
    }

    while (left) {
      head->next = left;
      left = left->next;
      head = head->next;
    }

    while (right) {
      head->next = right;
      right = right->next;
      head = head->next;
    }

    head->next = nullptr;

    return root;
  }
};

int main() {
  return 0;
}
