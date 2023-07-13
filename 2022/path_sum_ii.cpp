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
  typedef vector<int> vint;
  typedef TreeNode node;

  int target = 0;
  vector<vint> answer;

  void __rec__(node* root, vector<int> path, int current = 0) {
    if (root == nullptr)
      return;

    bool child_exists = false;
    path.push_back(root->val);
    if (root->left) {
      child_exists = true;
      __rec__(root->left, path, current + root->val);
    }
    if (root->right) {
      child_exists = true;
      __rec__(root->right, path, current + root->val);
    }
    if (child_exists)
      return;
    else if (current + root->val == target)
      answer.push_back(path);
  }

  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    if (root == nullptr)
      return {};
    target = targetSum;
    __rec__(root, {});
    return answer;
  }
};
