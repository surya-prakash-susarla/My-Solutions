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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
 public:
  using node = TreeNode;

  bool find_path(node* current, const node* target, vector<node*>& path) {
    if (current == nullptr)
      return false;
    if (current == target) {
      path.push_back(current);
      return true;
    }
    bool left = find_path(current->left, target, path);
    if (left) {
      path.push_back(current);
      return true;
    }
    bool right = find_path(current->right, target, path);
    if (right) {
      path.push_back(current);
      return true;
    }
    return false;
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* a, TreeNode* b) {
    if (root == nullptr or a == nullptr or b == nullptr)
      return nullptr;

    vector<node*> a_path, b_path;
    find_path(root, a, a_path);
    find_path(root, b, b_path);

    vector<node*>::iterator it = find_first_of(a_path.begin(), a_path.end(),
                                               b_path.begin(), b_path.end());
    return *it;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
