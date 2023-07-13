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

  node* __rec__(int pb,
                int pe,
                int ib,
                int ie,
                const vector<int>& pre,
                const vector<int>& in) {
    if (pe < pb or ie < ib)
      return nullptr;
    if (pe == pb and ie == ib)
      return new node(pre[pe]);

    int root_element = pre[pb];
    int root_index = -1;
    for (int i = ib; i <= ie; i++)
      if (in[i] == root_element) {
        root_index = i;
        break;
      }

    node* root = new node(pre[pb]);
    root->left =
        __rec__(pb + 1, pb + (root_index - ib), ib, root_index - 1, pre, in);
    root->right =
        __rec__(pb + (root_index - ib) + 1, pe, root_index + 1, ie, pre, in);
    return root;
  }

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return __rec__(0, preorder.size() - 1, 0, inorder.size() - 1, preorder,
                   inorder);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
