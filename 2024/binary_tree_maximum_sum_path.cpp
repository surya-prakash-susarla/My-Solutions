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

  int answer = INT_MIN;

  int get_sum(node* root) {
    int left_sum = root->left ? get_sum(root->left) : INT_MIN;
    int right_sum = root->right ? get_sum(root->right) : INT_MIN;

    int return_value = root->val;
    answer = max(answer, root->val);
    if (left_sum != INT_MIN and right_sum != INT_MIN) {
      return_value =
          max({return_value, root->val + left_sum, root->val + right_sum});
      answer = max(answer, left_sum + right_sum + root->val);
    } else if (left_sum != INT_MIN) {
      return_value = max({return_value, root->val + left_sum});
    } else if (right_sum != INT_MIN) {
      return_value = max({return_value, root->val + right_sum});
    }
    answer = max(answer, return_value);
    return return_value;
  }

  int maxPathSum(TreeNode* root) {
    get_sum(root);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
