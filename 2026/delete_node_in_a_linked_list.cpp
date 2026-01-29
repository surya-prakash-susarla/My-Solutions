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
  void deleteNode(ListNode* start) {
    typedef ListNode node;

    bool is_end = false;

    node* current;
    for (current = start; not is_end;) {
      node* next = current->next;
      swap(next->val, current->val);
      if (not next->next)
        is_end = true;
      else
        current = current->next;
    }

    current->next = nullptr;
  }
};
