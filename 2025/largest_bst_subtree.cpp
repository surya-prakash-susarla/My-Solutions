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
  typedef struct __result {
    bool is_bst;
    int minval;
    int maxval;
    int count;

    __result() {
      is_bst = true;
      minval = INT_MAX;
      maxval = INT_MIN;
      count = 0;
    }

    __result(bool bst) {
      is_bst = bst;
      minval = INT_MAX;
      maxval = INT_MIN;
      count = 0;
    }
  } _result;

  typedef TreeNode node;

  int answer = 0;

  _result __rec__(node* root) {
    if (not root)
      return _result();

    _result left = __rec__(root->left);
    _result right = __rec__(root->right);

    if (not left.is_bst or not right.is_bst)
      return _result(false);

    if (left.maxval >= root->val) {
      return _result(false);
    }
    if (right.minval <= root->val) {
      return _result(false);
    }

    _result current;
    current.minval = min(left.minval, root->val);
    current.maxval = max(root->val, right.maxval);
    current.count = 1 + left.count + right.count;

    answer = max(answer, current.count);

    return current;
  }

  int largestBSTSubtree(TreeNode* root) {
    __rec__(root);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
