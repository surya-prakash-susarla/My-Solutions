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
  int answer = 0;
  int low;
  int high;

  typedef TreeNode node;

  void __rec__(node* root) {
    if (not root)
      return;

    __rec__(root->left);
    __rec__(root->right);

    if (root->val > high or root->val < low)
      return;

    answer += root->val;
  }

  int rangeSumBST(TreeNode* root, int low, int high) {
    this->low = low;
    this->high = high;

    __rec__(root);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
