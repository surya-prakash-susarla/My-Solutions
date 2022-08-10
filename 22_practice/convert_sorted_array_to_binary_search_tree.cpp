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
  typedef vector<int> vint;

  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return __rec__(0, nums.size() - 1, nums);
  }

  node* __rec__(int start, int end, const vint& values) {
    if (start > end or start < 0 or end >= values.size())
      return nullptr;

    int mid = (start + end) / 2;
    // cout << "limits : " << start << " " << end << endl;
    // cout << "mid value : " << mid << " " << values[mid] << endl;
    node* root = new node(values[mid]);
    root->left = __rec__(start, mid - 1, values);
    root->right = __rec__(mid + 1, end, values);
    return root;
  }
};
