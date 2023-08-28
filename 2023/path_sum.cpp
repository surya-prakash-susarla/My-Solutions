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

  bool __rec__(node* root, const int current, const int target) {
    if (root->left or root->right) {
      bool left =
          root->left ? __rec__(root->left, root->val + current, target) : false;
      bool right = root->right
                       ? __rec__(root->right, root->val + current, target)
                       : false;
      return left or right;
    }
    return (root->val + current) == target;
  }

  bool hasPathSum(TreeNode* root, int target) {
    if (not root)
      return false;
    return __rec__(root, 0, target);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
