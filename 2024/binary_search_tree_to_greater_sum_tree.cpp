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

  int __rec__(node* root, int value) {
    if (root == nullptr)
      return value;

    int return_value = __rec__(root->right, value);
    root->val += return_value;
    return_value = __rec__(root->left, root->val);
    return return_value;
  }

  TreeNode* bstToGst(TreeNode* root) {
    __rec__(root, 0);
    return root;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
