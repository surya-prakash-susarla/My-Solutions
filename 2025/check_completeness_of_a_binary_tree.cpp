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
  bool isCompleteTree(TreeNode* root) {
    typedef TreeNode node;

    if (not root)
      return true;

    int level = 0;
    queue<node*> current;

    current.push(root);

    auto is_terminal_level = [](queue<node*>& current) -> bool {
      for (; not current.empty(); current.pop()) {
        node* top = current.front();
        if (top->left or top->right)
          return false;
      }
      return true;
    };

    while (not current.empty()) {
      if (current.size() != pow(2, level)) {
        return is_terminal_level(current);
      }

      queue<node*> next;
      bool can_have_children = true;
      for (; not current.empty(); current.pop()) {
        node* top = current.front();
        if (not top->left and not top->right) {
          can_have_children = false;
          continue;
        }

        if (not can_have_children) {
          return false;
        }

        if (not top->left) {
          return false;
        } else if (not top->right) {
          next.push(top->left);
          can_have_children = false;
        } else {
          // both children exist.
          next.push(top->left);
          next.push(top->right);
        }
      }

      swap(current, next);
      level++;
    }

    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
