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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
 public:
  typedef TreeNode node;

  node* answer = nullptr;

  node* p;
  node* q;

  pair<bool, bool> __rec__(node* root) {
    if (not root)
      return {false, false};

    pair<bool, bool> left = __rec__(root->left);
    pair<bool, bool> right = __rec__(root->right);

    left.first |= right.first;
    left.second |= right.second;

    if (root == p)
      left.first = true;
    if (root == q)
      left.second = true;

    if (left.first and left.second and not answer)
      answer = root;

    return left;
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    this->p = p;
    this->q = q;
    __rec__(root);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
