#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>


// Problem:
// https://leetcode.com/problems/delete-leaves-with-a-given-value/submissions/

typedef long long int llint;
typedef long double ldouble;

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
  typedef TreeNode tn;

  bool __prune__(tn* node, const int& value) {
    if (node == nullptr)
      return false;
    const bool lp = __prune__(node->left, value);
    const bool rp = __prune__(node->right, value);

    if (lp) {
      delete node->left;
      node->left = nullptr;
    }
    if (rp) {
      delete node->right;
      node->right = nullptr;
    }

    const bool should_del = (node->left == nullptr) and
                            (node->right == nullptr) and (node->val == value);

    return should_del;
  }

  TreeNode* removeLeafNodes(TreeNode* root, int target) {
    const bool dr = __prune__(root, target);
    if (dr) {
      root = nullptr;
    }
    return root;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
