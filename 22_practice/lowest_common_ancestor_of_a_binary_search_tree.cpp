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

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    __calc__(root, p, q);
    return answer;
  }

  typedef TreeNode node;
  typedef pair<bool, bool> pbool;

  void __update__(pbool& a, const pbool& b) {
    a.first = a.first or b.first;
    a.second = a.second or b.second;
  }

  pair<bool, bool> __calc__(node* current, node* p, node* q) {
    if (current == nullptr)
      return {false, false};

    pbool result = {(current == p), (current == q)};
    __update__(result, __calc__(current->left, p, q));
    __update__(result, __calc__(current->right, p, q));

    if (result == pbool(true, true) and answer == nullptr) {
      answer = current;
    }

    return result;
  }

  node* answer = nullptr;
};
