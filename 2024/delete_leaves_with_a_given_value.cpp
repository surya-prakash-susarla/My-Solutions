#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

typedef long long int llint;
typedef long long unsigned int ullint;

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

  bool __rec__(node* root, const int target) {
    if (not root)
      return false;

    if (__rec__(root->left, target))
      root->left = nullptr;

    if (__rec__(root->right, target))
      root->right = nullptr;

    if (not root->left and not root->right and root->val == target)
      return true;

    return false;
  }

  TreeNode* removeLeafNodes(TreeNode* root, int target) {
    return __rec__(root, target) ? nullptr : root;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
