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

  vector<node*> values;

  void list(node* root) {
    if (not root)
      return;

    list(root->left);
    values.push_back(root);
    list(root->right);
  }

  node* make(int start, int end) {
    if (start > end)
      return nullptr;

    int ind = (start + end) / 2;
    node* current = values[ind];
    current->left = make(start, ind - 1);
    current->right = make(ind + 1, end);
    return current;
  }

  TreeNode* balanceBST(TreeNode* root) {
    list(root);
    return make(0, values.size() - 1);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
