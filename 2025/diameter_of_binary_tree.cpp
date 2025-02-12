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

  int value = -1;

  int __rec__(node* root) {
    if (not root)
      return 0;

    int left_depth = __rec__(root->left);
    int right_depth = __rec__(root->right);

    value = max(value, left_depth + right_depth);

    return max(left_depth + 1, right_depth + 1);
  }

  int diameterOfBinaryTree(TreeNode* root) {
    __rec__(root);
    return value;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
