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

  int global_min = std::numeric_limits<int>::max();

  void __rec__(const node* root, const int cd) {
    if (root == nullptr)
      return;

    if (root->left == nullptr && root->right == nullptr) {
      global_min = min(global_min, cd);
      return;
    }

    if (cd + 1 >= global_min)
      return;

    __rec__(root->left, cd + 1);
    __rec__(root->right, cd + 1);

    return;
  }

  int minDepth(TreeNode* root) {
    if (root == nullptr)
      return 0;
    __rec__(root, 1);
    return global_min;
  }
};
