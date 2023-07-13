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

  bool __rec__(node* first, node* second) {
    if (first == nullptr and second == nullptr)
      return true;
    if (first == nullptr or second == nullptr)
      return false;
    if (first->val != second->val)
      return false;
    return __rec__(first->left, second->left) and
           __rec__(first->right, second->right);
  }

  bool isSameTree(TreeNode* p, TreeNode* q) { return __rec__(p, q); }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
