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

  int maxval = INT_MIN;
  node* answer = nullptr;

  int __rec__(node* root, int cd) {
    if (not root)
      return cd - 1;

    int left_depth = __rec__(root->left, cd + 1);
    int right_depth = __rec__(root->right, cd + 1);

    int max_depth = max(left_depth, right_depth);

    if (max_depth >= maxval and left_depth == right_depth) {
      answer = root;
      maxval = max_depth;
    }

    return max_depth;
  }

  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    __rec__(root, 1);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
