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
  vector<int> rightSideView(TreeNode* root) {
    if (root == nullptr)
      return {};

    typedef TreeNode node;
    typedef vector<int> vint;
    typedef queue<node*> qnode;

    qnode current;
    current.push(root);
    vint answer;
    while (not current.empty()) {
      qnode next;
      while (not current.empty()) {
        node* cnode = current.front();
        current.pop();
        if (current.empty())
          answer.push_back(cnode->val);
        if (cnode->left)
          next.push(cnode->left);
        if (cnode->right)
          next.push(cnode->right);
      }
      swap(current, next);
    }
    return answer;
  }
};
