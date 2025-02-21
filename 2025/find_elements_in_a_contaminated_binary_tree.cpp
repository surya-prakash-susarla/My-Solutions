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
class FindElements {
 public:
  typedef TreeNode node;

  node* head;

  void fix(node* root, int x) {
    if (not root)
      return;

    root->val = x;
    fix(root->left, (2 * x) + 1);
    fix(root->right, (2 * x) + 2);
  }

  FindElements(TreeNode* root) {
    head = root;
    fix(root, 0);
  }

  bool search(node* root, const int target) {
    if (not root)
      return false;

    if (root->val == target)
      return true;

    return search(root->left, target) or search(root->right, target);
  }

  bool find(int target) { return search(head, target); }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
