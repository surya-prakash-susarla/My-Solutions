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
  string tree2str(TreeNode* root) {
    if (root == nullptr)
      return {};

    string answer = to_string(root->val);

    string left = tree2str(root->left);
    string right = tree2str(root->right);

    if (not left.empty() or not right.empty())
      left = '(' + left + ')';
    if (not right.empty())
      right = '(' + right + ')';

    return answer + left + right;
  }
};

int main() {
  return 0;
}
