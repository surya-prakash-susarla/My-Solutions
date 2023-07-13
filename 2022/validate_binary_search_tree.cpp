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
  bool isValidBST(TreeNode* root) {
    if (root == nullptr)
      return true;
    return __calc__(root);
  }

  typedef TreeNode node;

  bool __calc__(node* root,
                optional<int> left = nullopt,
                optional<int> right = nullopt) {
    if (left and root->val <= *left)
      return false;
    if (right and root->val >= *right)
      return false;

    bool answer = true;

    if (root->left) {
      if (root->left->val < root->val)
        answer = answer and __calc__(root->left, left, root->val);
      else
        return false;
    }

    if (root->right) {
      if (root->right->val > root->val)
        answer = answer and __calc__(root->right, root->val, right);
      else
        return false;
    }

    return answer;
  }
};
