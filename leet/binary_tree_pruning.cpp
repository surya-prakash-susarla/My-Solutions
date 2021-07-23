#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

// Problem:

typedef long long int llint;
typedef long double ldouble;

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
  using node = TreeNode;

  bool __rec__(node* root) {
    bool is_left_valid = false, is_right_valid = false;
    if (root->left) {
      is_left_valid = __rec__(root->left);
      if (!is_left_valid) {
        delete root->left;
        root->left = nullptr;
      }
    }
    if (root->right) {
      is_right_valid = __rec__(root->right);
      if (!is_right_valid) {
        delete root->right;
        root->right = nullptr;
      }
    }
    return is_left_valid or is_right_valid or root->val == 1;
  }

  TreeNode* pruneTree(TreeNode* root) {
    return root == nullptr or not __rec__(root) ? nullptr : root;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
