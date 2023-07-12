#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define node TreeNode

class Solution {
 public:
  int answer = -1, level = -1;

  void calc(node* root, int depth) {
    if (root == NULL)
      return;
    if (depth > level)
      level = depth, answer = root->val;
    calc(root->left, depth + 1);
    calc(root->right, depth + 1);
    return;
  }

  int findBottomLeftValue(TreeNode* root) {
    calc(root, 0);
    return answer;
  }
};