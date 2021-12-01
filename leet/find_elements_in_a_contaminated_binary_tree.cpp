#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

// Problem:

typedef long long int llint;
typedef long double ldouble;

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
class FindElements {
 public:
  using node = TreeNode;

  FindElements(TreeNode* value) {
    if (value) {
      value->val = 0;
      __fix__(value);
    }
  }

  bool find(int target) { return values.find(target) != values.end(); }

 private:
  set<int> values;

  void __fix__(node* root) {
    if (root == nullptr)
      return;
    values.insert(root->val);
    if (root->right != nullptr) {
      root->right->val = root->val * 2 + 2;
      __fix__(root->right);
    }
    if (root->left != nullptr) {
      root->left->val = root->val * 2 + 1;
      __fix__(root->left);
    }
    return;
  }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
