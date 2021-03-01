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
// https://leetcode.com/problems/balance-a-binary-search-tree/submissions/

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

  void __read__(tn* root, vector<int>& values) {
    if (root == nullptr)
      return;
    values.push_back(root->val);
    __read__(root->left, values);
    __read__(root->right, values);
  }

  tn* __create__(const int li, const int ui, const vector<int>& values) {
    if (li > ui or min(li, ui) < 0 or li >= values.size())
      return nullptr;
    int ci = (li + ui) / 2;
    tn* cnode = new tn;
    cnode->val = values[ci];
    cnode->left = __create__(li, ci - 1, values);
    cnode->right = __create__(ci + 1, ui, values);
    return cnode;
  }

  TreeNode* balanceBST(TreeNode* root) {
    vector<int> values;
    __read__(root, values);
    sort(values.begin(), values.end());
    tn* node = __create__(0, values.size(), values);
    return node;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
