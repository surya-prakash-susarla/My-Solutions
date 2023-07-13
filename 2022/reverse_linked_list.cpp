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
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr)
      return nullptr;
    typedef ListNode node;
    node* prev = nullptr;
    node* current = head;
    node* next = head->next;

    while (next) {
      current->next = prev;
      node* temp = next->next;
      next->next = current;
      prev = current;
      current = next;
      next = temp;
    }

    return current;
  }
};
