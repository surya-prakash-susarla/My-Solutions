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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    typedef ListNode node;

    stack<node*> temp_st;

    node* temp = head;
    while (temp) {
      temp_st.push(temp);
      temp = temp->next;
    }

    node* last = nullptr;
    while (--n) {
      last = temp_st.top();
      temp_st.pop();
    }

    temp_st.pop();

    if (not temp_st.empty())
      temp_st.top()->next = last;

    node* final_head = temp_st.empty() ? last : nullptr;
    while (not temp_st.empty()) {
      final_head = temp_st.top();
      temp_st.pop();
    }

    return final_head;
  }
};

int main() {
  return 0;
}
