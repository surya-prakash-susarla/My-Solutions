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

  vector<string> __rec__(node* root) {
    if (root == nullptr)
      return {};

    const string current = string(1, 'a' + root->val);

    if (not root->left and not root->right)
      return {current};

    vector<string> left = __rec__(root->left);
    vector<string> right = __rec__(root->right);

    for (string& i : left)
      i += current;
    for (string& i : right)
      i += current;

    left.insert(left.end(), right.begin(), right.end());

    return left;
  }

  string smallestFromLeaf(TreeNode* root) {
    vector<string> values = __rec__(root);
    sort(values.begin(), values.end());
    return values[0];
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
