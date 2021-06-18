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

  int target = -1;

  bool __rec__(const node* root, const int cs) {
    if (root == nullptr)
      return false;

    if (root->left == nullptr and root->right == nullptr) {
      return (root->val + cs) == target;
    }

    const bool left = __rec__(root->left, cs + root->val);
    if (left)
      return true;
    const bool right = __rec__(root->right, cs + root->val);
    return right;
  }

  bool hasPathSum(TreeNode* root, int targetSum) {
    target = targetSum;
    return __rec__(root, 0);
  }
};
