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
  static constexpr int minvalue = numeric_limits<int>::min();
  int answer = minvalue;

  int __rec__(node* root) {
    if (root == nullptr)
      return minvalue;

    int left = __rec__(root->left);
    int right = __rec__(root->right);

    int left_inclusive = left == minvalue ? minvalue : left + root->val;
    int right_inclusive = right == minvalue ? minvalue : right + root->val;

    int complete = root->val;
    if (left != minvalue)
      complete += left;
    if (right != minvalue)
      complete += right;

    answer =
        max({answer, left_inclusive, right_inclusive, complete, root->val});

    return max({left_inclusive, right_inclusive, root->val});
  }

  int maxPathSum(TreeNode* root) {
    __rec__(root);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
