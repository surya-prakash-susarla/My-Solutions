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
  ListNode* deleteDuplicates(ListNode* head) {
    if (not head)
      return nullptr;

    typedef ListNode node;
    stack<node*> values;

    bool should_del = false;

    for (node* root = head; root; root = root->next) {
      if (not values.empty() and values.top()->val == root->val) {
        should_del = true;
      } else {
        if (should_del and not values.empty())
          values.pop();
        should_del = false;
        if (not values.empty()) {
          values.top()->next = root;
        }
        values.push(root);
      }
    }
    if (should_del) {
      values.pop();
      if (not values.empty())
        values.top()->next = nullptr;
    }

    node* root = nullptr;
    for (; values.size() > 1; values.pop())
      ;
    if (not values.empty())
      root = values.top();
    return root;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
