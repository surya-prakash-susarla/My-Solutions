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
  bool hasPathSum(TreeNode* root, const int& targetSum, int current = 0) {
    typedef TreeNode node;

    if (root == nullptr)
      return false;

    bool child_exists = false;

    if (root->left) {
      child_exists = true;
      if (hasPathSum(root->left, targetSum, current + root->val))
        return true;
    }
    if (root->right) {
      child_exists = true;
      if (hasPathSum(root->right, targetSum, current + root->val))
        return true;
    }
    if (child_exists)
      return false;
    else
      return targetSum == current + root->val;
  }
};
