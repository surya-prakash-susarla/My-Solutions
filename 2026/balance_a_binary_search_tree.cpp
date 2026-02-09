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

  vector<int> walk(node* root) {
    if (not root)
      return {};
    vector<int> left = walk(root->left);
    left.push_back(root->val);
    vector<int> right = walk(root->right);
    left.insert(left.end(), right.begin(), right.end());
    return left;
  }

  node* create(int i, int j, const vector<int>& values) {
    if (i > j)
      return nullptr;

    int mid = (i + j) / 2;
    node* root = new node(values[mid]);
    root->left = create(i, mid - 1, values);
    root->right = create(mid + 1, j, values);
    return root;
  }

  TreeNode* balanceBST(TreeNode* root) {
    vector<int> values = walk(root);
    return create(0, values.size() - 1, values);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
