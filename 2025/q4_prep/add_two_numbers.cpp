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
  ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
    node* a_head = a;
    node* b_head = b;

    node* answer = nullptr;
    node* current = nullptr;

    int prev = 0;

    while (a_head and b_head) {
      int a_val = a_head->val;
      int b_val = b_head->val;
      a_head = a_head->next;
      b_head = b_head->next;

      int current_sum = a_val + b_val + prev;
      int rem = (current_sum % 10);
      if (current_sum >= 10) {
        prev = 1;
      } else {
        prev = 0;
      }

      node* temp = new node(rem);
      if (current) {
        current->next = temp;
        current = temp;
      } else {
        current = temp;
        answer = current;
      }
    }

    while (a_head) {
      int sum = a_head->val + prev;
      a_head = a_head->next;
      int rem = sum % 10;
      if (sum >= 10)
        prev = 1;
      else
        prev = 0;
      if (current) {
        current->next = new node(rem);
        current = current->next;
      } else {
        current = new node(rem);
        answer = current;
      }
    }

    while (b_head) {
      int sum = b_head->val + prev;
      b_head = b_head->next;
      int rem = sum % 10;
      if (sum >= 10)
        prev = 1;
      else
        prev = 0;
      if (current) {
        current->next = new node(rem);
        current = current->next;
      } else {
        current = new node(rem);
        answer = current;
      }
    }

    if (prev != 0)
      current->next = new node(prev);

    return answer;
  }
};
