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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  typedef ListNode lnode;
  typedef TreeNode tnode;

  lnode* find_mid(lnode* start, lnode* end) {
    if (start == end)
      return nullptr;
    lnode* s = start;

    if (start->next == end)
      return s;

    lnode* ss = start;

    while (true) {
      s = s->next;
      ss = ss->next;
      if (ss->next == end)
        return s;
      ss = ss->next;
      if (ss->next == end)
        return s;
    }

    return nullptr;
  }

  tnode* __rec__(lnode* start, lnode* end) {
    if (start == end)
      return nullptr;

    lnode* mid_value = find_mid(start, end);

    tnode* current = new tnode();
    current->val = mid_value->val;
    current->left = __rec__(start, mid_value);
    current->right = __rec__(mid_value->next, end);

    return current;
  }

  TreeNode* sortedListToBST(ListNode* head) {
    if (head == nullptr)
      return nullptr;

    return __rec__(head, nullptr);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
