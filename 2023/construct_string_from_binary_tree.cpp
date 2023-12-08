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

  string __rec__(node* root) {
    if (not root)
      return "";

    string left = __rec__(root->left);
    string right = __rec__(root->right);

    string children;
    if (not left.empty() and not right.empty())
      children = left + right;
    else if (left.empty() and not right.empty())
      children = "()" + right;
    else
      children = left;

    return "(" + to_string(root->val) + children + ")";
  }

  string tree2str(TreeNode* root) {
    if (not root)
      return "";
    string children;
    string left = __rec__(root->left);
    string right = __rec__(root->right);
    if (not left.empty() and not right.empty())
      children = left + right;
    else if (left.empty() and not right.empty())
      children = "()" + right;
    else
      children = left;
    return to_string(root->val) + children;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
