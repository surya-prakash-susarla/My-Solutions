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
  typedef ListNode node;

  bool hasCycle(ListNode* head) {
    if (not head)
      return false;

    node* slow = head;
    node* fast = head;

    while (true) {
      slow = slow->next;
      fast = fast->next;
      if (not fast or not fast->next)
        return false;
      fast = fast->next;
      if (slow == fast)
        return true;
    }
    return false;
  }
};
