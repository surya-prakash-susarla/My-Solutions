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

  void __rec__(node* current, int current_depth, int target_depth, int val) {
    if (current_depth + 1 == target_depth) {
      node* left = new node(val);
      node* right = new node(val);

      if (current->left)
        left->left = current->left;
      if (current->right)
        right->right = current->right;

      current->left = left;
      current->right = right;

      return;

    } else {
      if (current->left)
        __rec__(current->left, current_depth + 1, target_depth, val);
      if (current->right)
        __rec__(current->right, current_depth + 1, target_depth, val);
    }
  }

  TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if (depth == 1) {
      node* temp = new node(val);
      temp->left = root;
      return temp;
    } else {
      __rec__(root, 1, depth, val);
      return root;
    }
  }
};

int main() {
  return 0;
}
