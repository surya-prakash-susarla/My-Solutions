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
  typedef pair<int, int> pint;

  int answer = 0;

  pint __rec__(node* root) {
    if (not root)
      return {0, 0};

    pint left = __rec__(root->left);
    pint right = __rec__(root->right);

    pint return_value = {left.first + right.first + root->val,
                         left.second + right.second + 1};

    if (root->val == (return_value.first / return_value.second))
      answer++;

    return return_value;
  }

  int averageOfSubtree(TreeNode* root) {
    __rec__(root);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
