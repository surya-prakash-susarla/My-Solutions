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

  vector<ListNode*> splitCircularLinkedList(ListNode* og_head) {
    if (not og_head)
      return {nullptr, nullptr};

    int count = 0;

    node* end_node = nullptr;

    for (node* temp = og_head;; temp = temp->next) {
      count++;
      if (temp->next == og_head) {
        end_node = temp;
        break;
      }
    }

    int mid_node_count = ceil((double)count / 2);

    node* mid_node = nullptr;
    for (node* temp = og_head; mid_node_count != 0; temp = temp->next) {
      mid_node_count--;
      if (mid_node_count == 0) {
        mid_node = temp;
      }
    }

    node* second_half_head = mid_node->next;

    mid_node->next = og_head;
    end_node->next = second_half_head;

    return {og_head, second_half_head};
  }
};
