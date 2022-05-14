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
  typedef vector<int> vint;

  int answer = 0;

  int buildInt(const vint& values) {
    int mul = pow(10, values.size() - 1);
    int answer = 0;
    for (int i = 0; i < values.size(); i++) {
      answer += (values[i] * mul);
      mul /= 10;
    }
    return answer;
  }

  void __rec__(node* root, vint path = {}) {
    bool child_exists = false;
    path.push_back(root->val);
    if (root->left) {
      child_exists = true;
      __rec__(root->left, path);
    }
    if (root->right) {
      child_exists = true;
      __rec__(root->right, path);
    }
    if (not child_exists) {
      answer += buildInt(path);
    }
  }

  int sumNumbers(TreeNode* root) {
    if (root == nullptr)
      return 0;
    __rec__(root);
    return answer;
  }
};
