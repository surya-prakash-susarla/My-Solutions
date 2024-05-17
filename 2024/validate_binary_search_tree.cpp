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
  typedef long long int llint;

  bool is_valid(node* root, const llint left, const llint right) {
    if (not root)
      return true;

    if (root->val > left and root->val < right) {
      const bool left_valid = is_valid(root->left, left, root->val);
      const bool right_valid = is_valid(root->right, root->val, right);
      return left_valid and right_valid;
    }

    return false;
  }

  bool isValidBST(TreeNode* root) {
    return is_valid(root, numeric_limits<llint>::min(),
                    numeric_limits<llint>::max());
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
