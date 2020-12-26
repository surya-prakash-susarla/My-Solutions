/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    if (root == NULL)
      return new TreeNode(val);
    if (val < root->val) {
      root->right = insertIntoMaxTree(root->right, val);
      return root;
    } else {
      TreeNode* new_root = new TreeNode(val);
      new_root->left = root;
      return new_root;
    }
  }
};