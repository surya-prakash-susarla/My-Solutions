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

  node* __rec__(node* root, int value) {
    if (not root)
      return new node(value);

    if (root->val < value) {
      root->right = __rec__(root->right, value);
    } else {
      root->left = __rec__(root->left, value);
    }
    return root;
  }

  TreeNode* insertIntoBST(TreeNode* root, int val) {
    return __rec__(root, val);
  }
};
