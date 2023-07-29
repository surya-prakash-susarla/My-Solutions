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
  using nm = numeric_limits<llint>;

  bool is_valid(node* root, llint ll, llint rl) {
    if (root == nullptr)
      return true;

    bool left_valid = is_valid(root->left, ll, root->val);
    bool right_valid = is_valid(root->right, root->val, rl);

    if (root->val <= ll or root->val >= rl)
      return false;

    return left_valid and right_valid;
  }

  bool isValidBST(TreeNode* root) {
    return is_valid(root, nm::min(), nm::max());
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
