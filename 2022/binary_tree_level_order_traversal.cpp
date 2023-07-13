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
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr)
      return {};

    typedef vector<int> vint;
    typedef TreeNode node;
    typedef queue<node*> qnode;

    qnode current;

    current.push(root);
    vector<vint> answer;

    while (not current.empty()) {
      qnode next;
      vint temp;
      while (not current.empty()) {
        node* cnode = current.front();
        temp.push_back(cnode->val);
        current.pop();
        if (cnode->left)
          next.push(cnode->left);
        if (cnode->right)
          next.push(cnode->right);
      }
      answer.emplace_back(temp);
      current = next;
    }

    return answer;
  }
};
