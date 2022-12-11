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
  typedef long long int llint;

  llint answer = numeric_limits<llint>::min();

  llint __rec__(node* root) {
    if (root == nullptr)
      return 0;

    llint left = __rec__(root->left);
    llint right = __rec__(root->right);

    answer = max({answer, left + right + root->val, left + root->val,
                  right + root->val, (llint)root->val});

    llint retval = max({left + root->val, right + root->val, (llint)root->val});

    return retval;
  }

  int maxPathSum(TreeNode* root) {
    answer = max(answer, __rec__(root));
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
