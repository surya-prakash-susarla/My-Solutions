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
  using node = TreeNode;
  using vint = vector<int>;

  node* __rec__(const vint& pre,
                int& pind,
                const vint& in,
                const int& il,
                const int& ir) {
    if (il > ir || pind >= pre.size())
      return nullptr;

    const int& croot = pre[pind];
    const int cri = find(in.begin(), in.end(), croot) - in.begin();
    if (cri < il || cri > ir)
      return nullptr;
    pind++;
    node* root = new node(croot);
    root->left = __rec__(pre, pind, in, il, cri - 1);
    root->right = __rec__(pre, pind, in, cri + 1, ir);

    return root;
  }

  TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
    int temp = 0;
    return __rec__(pre, temp, in, 0, in.size() - 1);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
