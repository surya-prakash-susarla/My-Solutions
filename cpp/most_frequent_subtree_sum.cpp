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
  int calc(node* root, map<int, int>& values) {
    if (root == NULL)
      return 0;
    int current =
        calc(root->left, values) + calc(root->right, values) + root->val;
    values[current] += 1;
    return current;
  }

  vector<int> findFrequentTreeSum(TreeNode* root) {
    map<int, int> values;
    calc(root, values);
    int freq = -1;
    for (auto it : values)
      if (it.second > freq)
        freq = it.second;
    vector<int> answer;
    for (auto it : values)
      if (it.second == freq)
        answer.push_back(it.first);
    return answer;
  }
};