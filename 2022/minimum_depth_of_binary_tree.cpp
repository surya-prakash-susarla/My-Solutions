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
  int minDepth(TreeNode* root) {
    if (!root)
      return 0;
    typedef TreeNode node;
    typedef queue<node*> qnode;
    int depth = 0;
    qnode current;
    current.push(root);
    while (not current.empty()) {
      qnode next;
      depth++;
      while (not current.empty()) {
        node* cnode = current.front();
        if (cnode->left == nullptr and cnode->right == nullptr)
          return depth;
        if (cnode->left)
          next.push(cnode->left);
        if (cnode->right)
          next.push(cnode->right);
        current.pop();
      }
      current = next;
    }
    return depth;
  }
};
