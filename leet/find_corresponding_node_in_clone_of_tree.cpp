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
// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

typedef long long int llint;
typedef long double ldouble;

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
  typedef TreeNode tn;

  tn* __calc__(const tn* target, const tn* oi, tn* di) {
    if (oi == nullptr or di == nullptr)
      return nullptr;

    if (oi == target)
      return di;

    tn* answer = __calc__(target, oi->left, di->left);
    if (answer)
      return answer;
    answer = __calc__(target, oi->right, di->right);
    return answer;
  }

  TreeNode* getTargetCopy(TreeNode* original,
                          TreeNode* cloned,
                          TreeNode* target) {
    return __calc__(target, original, cloned);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
