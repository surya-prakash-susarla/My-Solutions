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
  typedef TreeNode node;
  void flatten(TreeNode* root) {
    if (root)
      __calc__(root);
  }

  typedef pair<node*, node*> range;
  range __calc__(node* root) {
    optional<range> left =
        root->left ? optional<range>(__calc__(root->left)) : nullopt;
    optional<range> right =
        root->right ? optional<range>(__calc__(root->right)) : nullopt;

    root->left = nullptr;
    range answer = {root, root};
    if (left.has_value()) {
      answer.first->right = left->first;
      answer.second = left->second;
    }
    if (right.has_value()) {
      answer.second->right = right->first;
      answer.second = right->second;
    }

    return answer;
  }
};
