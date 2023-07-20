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
class BSTIterator {
 public:
  typedef TreeNode node;
  void __rec__(node* root) {
    if (root == nullptr)
      return;
    __rec__(root->left);
    values.push(root->val);
    __rec__(root->right);
  }

  BSTIterator(TreeNode* root) { __rec__(root); }

  int next() {
    int _ = values.front();
    values.pop();
    return _;
  }

  bool hasNext() { return not values.empty(); }

  queue<int> values;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
