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
  typedef vector<int> vint;

  void __rec__(node* root, vint& values) {
    if (root == nullptr)
      return;
    bool used = false;
    if (root->left) {
      __rec__(root->left, values);
      used = true;
    }
    if (root->right) {
      __rec__(root->right, values);
      used = true;
    }
    if (not used) {
      values.push_back(root->val);
    }
    return;
  }

  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> values_1;
    __rec__(root1, values_1);

    vector<int> values_2;
    __rec__(root2, values_2);

    return values_1 == values_2;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
