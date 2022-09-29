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

  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int digit = -1;

    node* current = nullptr;
    node* answer = nullptr;

    while (l1 and l2) {
      int temp = l1->val + l2->val + (digit != -1 ? digit : 0);
      digit = temp / 10 != 0 ? temp / 10 : -1;
      temp = temp % 10;

      node* temp2 = new node(temp);

      if (current == nullptr) {
        answer = temp2;
        current = temp2;
      } else {
        current->next = temp2;
        current = current->next;
      }

      l1 = l1->next;
      l2 = l2->next;
    }

    while (l1) {
      int temp = (digit != -1 ? digit : 0) + l1->val;
      digit = temp / 10 != 0 ? temp / 10 : -1;
      temp = temp % 10;

      node* temp2 = new node(temp);
      current->next = temp2;
      current = temp2;

      l1 = l1->next;
    }

    while (l2) {
      int temp = (digit != -1 ? digit : 0) + l2->val;
      digit = temp / 10 != 0 ? temp / 10 : -1;
      temp = temp % 10;

      node* temp2 = new node(temp);
      current->next = temp2;
      current = temp2;

      l2 = l2->next;
    }

    if (digit != -1) {
      node* temp = new node(digit);
      current->next = temp;
    }

    return answer;
  }
};

int main() {
  return 0;
}
