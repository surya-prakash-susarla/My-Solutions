#include <bits/stdc++.h>
using namespace std;

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
  void __rec__(vector<int>& answer, TreeNode* root) {
    if (root == nullptr)
      return;

    __rec__(answer, root->left);
    answer.push_back(root->val);
    __rec__(answer, root->right);

    return;
  }

  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> answer;
    __rec__(answer, root);
    return answer;
  }
};

int main() {
  return 0;
}
