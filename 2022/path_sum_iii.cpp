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
  typedef long long int llint;
  typedef vector<llint> vint;

  int answer = 0;
  int target;
  vint path;

  void __rec__(node* root) {
    path.push_back(root->val);

    if (root->left)
      __rec__(root->left);
    if (root->right)
      __rec__(root->right);

    llint temp = 0;
    for (int i = path.size() - 1; i > -1; i--) {
      temp += path[i];
      if (temp == target)
        answer++;
    }

    path.pop_back();
  }

  int pathSum(TreeNode* root, int targetSum) {
    if (root == nullptr)
      return 0;
    target = targetSum;
    __rec__(root);
    return answer;
  }
};
