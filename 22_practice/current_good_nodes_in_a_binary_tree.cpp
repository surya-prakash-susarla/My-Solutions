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

  int answer = 0;

  void __rec__(node* root, int maxvalue) {
    if (root == nullptr)
      return;

    if (root->val >= maxvalue)
      answer++;

    maxvalue = max(maxvalue, root->val);

    __rec__(root->left, maxvalue);
    __rec__(root->right, maxvalue);

    return;
  }

  int goodNodes(TreeNode* root) {
    __rec__(root, numeric_limits<int>::min());

    return answer;
  }
};
