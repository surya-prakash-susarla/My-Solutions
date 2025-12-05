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

  ListNode* reverseList(ListNode* head) {
    if (not head)
      return head;

    stack<node*> values;
    for (; head; head = head->next) {
      values.push(head);
    }

    node* answer = values.top();
    node* current = values.top();
    values.pop();

    while (not values.empty()) {
      current->next = values.top();
      values.pop();
      current = current->next;
    }

    current->next = nullptr;

    return answer;
  }
};
