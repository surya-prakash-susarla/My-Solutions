#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

typedef long long int llint;
typedef long long unsigned int ullint;

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

  node* mid(node* start) {
    node* answer = start;
    node* lead = start;
    node* prev = nullptr;
    while (lead) {
      lead = lead->next;
      if (lead)
        lead = lead->next;
      prev = answer;
      answer = answer->next;
    }
    prev->next = nullptr;
    return answer;
  }

  node* __rec__(node* root) {
    if (root->next == nullptr)
      return root;

    node* mp = mid(root);
    node* right = mp;

    node* left = __rec__(root);
    right = __rec__(right);

    node* answer = nullptr;
    node* head = nullptr;

    while (left and right) {
      node* current = nullptr;
      if (left->val < right->val) {
        current = left;
        left = left->next;
      } else {
        current = right;
        right = right->next;
      }
      if (answer)
        answer->next = current;
      answer = current;
      if (not head)
        head = answer;
    }
    for (; left; left = left->next) {
      if (answer)
        answer->next = left;
      answer = left;
      if (not head)
        head = answer;
    }
    for (; right; right = right->next) {
      if (answer)
        answer->next = right;
      answer = answer->next;
      if (not head)
        head = answer;
    }
    return head;
  }

  ListNode* sortList(ListNode* head) {
    if (head == nullptr)
      return nullptr;
    return __rec__(head);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
