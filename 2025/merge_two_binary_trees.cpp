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

  TreeNode* mergeTrees(TreeNode* a, TreeNode* b) {
    if (not a and not b)
      return nullptr;

    if (not a)
      return b;
    if (not b)
      return a;

    node* current = new node();
    current->val = a->val + b->val;
    current->left = mergeTrees(a->left, b->left);
    current->right = mergeTrees(a->right, b->right);
    return current;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
