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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    typedef ListNode node;

    struct comp {
      bool operator()(const node* lhs, const node* rhs) const {
        return lhs->val <= rhs->val;
      }
    };

    multiset<node*, comp> values;
    for (node* i : lists) {
      node* j = i;
      while (j) {
        values.insert(j);
        j = j->next;
      }
    }

    node* begin = nullptr;
    node* root = nullptr;

    for (node* i : values) {
      if (begin == nullptr) {
        begin = i;
        root = i;
      } else {
        root->next = i;
        root = root->next;
        root->next = nullptr;
      }
    }

    return begin;
  }
};