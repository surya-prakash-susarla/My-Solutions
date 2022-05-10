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

  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr)
      return nullptr;

    int length = 0;
    node* temp = head;
    node* end = temp;
    while (temp) {
      length++;
      end = temp;
      temp = temp->next;
    }

    if (length == 1)
      return head;

    k %= length;
    if (k == 0)
      return head;

    int bp = length - k;
    int count = 0;
    temp = head;
    node* cut = temp;
    while (count != bp) {
      count++;
      cut = temp;
      temp = temp->next;
    }
    cut->next = nullptr;
    end->next = head;
    return temp;
  }
};
