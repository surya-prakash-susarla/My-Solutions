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

  pair<node*, node*> reverse(node* start, node* end) {
    node* head = start;
    node* next = start->next;

    while (head != end) {
      node* temp = next->next;
      next->next = head;
      head = next;
      next = temp;
    }

    return {head, start};
  }

  ListNode* reverseBetween(ListNode* head, int left, int right) {
    node* left_node = nullptr;
    node* right_node = nullptr;
    node* pre_left = nullptr;
    node* post_right = nullptr;

    int counter = 1;
    node* temp = head;
    while (counter <= right) {
      if (counter == left - 1)
        pre_left = temp;
      if (counter == left)
        left_node = temp;
      if (counter == right)
        right_node = temp;
      counter++;
      temp = temp->next;
    }
    post_right = temp;

    pair<node*, node*> reversed = reverse(left_node, right_node);

    if (pre_left)
      pre_left->next = reversed.first;

    reversed.second->next = post_right;

    return pre_left ? head : reversed.first;
  }
};
