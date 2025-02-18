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

  int answer = 0;

  void __rec__(node* root, int maxval) {
    if (root == nullptr)
      return;

    if (root->val >= maxval)
      answer++;

    maxval = max(maxval, root->val);

    __rec__(root->left, maxval);
    __rec__(root->right, maxval);
  }

  int goodNodes(TreeNode* root) {
    __rec__(root, INT_MIN);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
