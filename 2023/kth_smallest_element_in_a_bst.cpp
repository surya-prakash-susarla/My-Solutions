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

  optional<int> __rec__(node* root, int& k) {
    if (root == nullptr)
      return nullopt;

    if (k == 0)
      return root->val;

    optional<int> return_value = __rec__(root->left, k);
    if (return_value != nullopt)
      return return_value;

    if (--k == 0)
      return root->val;

    return_value = __rec__(root->right, k);
    if (return_value != nullopt)
      return return_value;

    return nullopt;
  }

  int kthSmallest(TreeNode* root, int k) {
    optional<int> return_value = __rec__(root, k);
    return return_value.value();
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
