#include <bits/stdc++.h>
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
  typedef TreeNode node;

  bool __rec__(node* root) {
    if (root == nullptr)
      return false;
    bool does_left_have_one = __rec__(root->left);
    bool does_right_have_one = __rec__(root->right);

    if (not does_left_have_one)
      root->left = nullptr;
    if (not does_right_have_one)
      root->right = nullptr;

    return does_left_have_one or does_right_have_one or (root->val == 1);
  }

  TreeNode* pruneTree(TreeNode* root) { return __rec__(root) ? root : nullptr; }
};

int main() {
  return 0;
}
