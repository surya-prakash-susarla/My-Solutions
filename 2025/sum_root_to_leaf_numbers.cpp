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

  void __calc__(node* root, int existing) {
    if (root == nullptr) {
      answer += existing;
      return;
    }

    if (not root->left and not root->right)
      return __calc__(nullptr, existing * 10 + root->val);

    if (root->left)
      __calc__(root->left, existing * 10 + root->val);

    if (root->right)
      __calc__(root->right, existing * 10 + root->val);
  }

  int sumNumbers(TreeNode* root) {
    __calc__(root, 0);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
