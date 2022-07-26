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
  typedef TreeNode node;
  typedef pair<bool, bool> pbool;

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    pbool temp = __calc__(root, p, q);
    return final_answer == nullptr ? root : final_answer;
  }

  const pbool true_all = {true, true};
  const pbool false_all = {false, false};

  pbool __calc__(node* root, node* first, node* second) {
    if (root == nullptr) {
      return false_all;
    }

    if (final_answer)
      return true_all;

    pbool answer = {false, false};
    if (root == first)
      answer.first = true;
    if (root == second)
      answer.second = true;

    if (answer == true_all) {
      set_answer(root);
      return true_all;
    }

    pbool left = __calc__(root->left, first, second);
    update_answer(answer, left);

    if (answer == true_all) {
      set_answer(root);
      return true_all;
    }

    pbool right = __calc__(root->right, first, second);
    update_answer(answer, right);

    if (answer == true_all) {
      set_answer(root);
      return true_all;
    }

    return answer;
  }

  void update_answer(pbool& answer, const pbool& temp) {
    answer.first = (answer.first || temp.first);
    answer.second = (answer.second || temp.second);
  }

  void set_answer(node* answer) {
    if (final_answer == nullptr)
      final_answer = answer;
  }

  node* final_answer = nullptr;
};