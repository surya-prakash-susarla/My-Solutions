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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root)
      return {};
    typedef TreeNode node;
    typedef queue<node*> qnode;
    typedef vector<int> vint;

    vector<vint> answer;
    qnode current;
    current.push(root);
    bool swap = false;

    while (not current.empty()) {
      qnode next;
      vint temp;
      while (not current.empty()) {
        node* cnode = current.front();
        temp.push_back(cnode->val);
        if (cnode->left)
          next.push(cnode->left);
        if (cnode->right)
          next.push(cnode->right);
        current.pop();
      }
      if (swap)
        reverse(temp.begin(), temp.end());
      swap = not swap;
      answer.emplace_back(temp);
      current = next;
    }

    return answer;
  }
};
