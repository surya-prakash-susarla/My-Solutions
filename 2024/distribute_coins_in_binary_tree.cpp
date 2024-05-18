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

  pair<int, int> __rec__(node* root) {
    if (not root)
      return {0, 0};
    const pair<int, int> left = __rec__(root->left);
    const pair<int, int> right = __rec__(root->right);
    const int req = (root->val - 1) + left.first + right.first;
    const int cost = left.second + right.second + (abs(req));
    return {req, cost};
  }

  int distributeCoins(TreeNode* root) { return __rec__(root).second; }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
