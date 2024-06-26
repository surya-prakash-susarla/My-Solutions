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

  void flatten(node* root, vector<node*>& ref) {
    if (not root)
      return;
    flatten(root->left, ref);
    ref.push_back(root);
    flatten(root->right, ref);
  }

  node* create(const vector<node*>& ref, int start, int end) {
    if (start == end)
      return nullptr;

    int mid = (start + end) / 2;
    ref[mid]->left = create(ref, start, mid);
    ref[mid]->right = create(ref, mid + 1, end);

    return ref[mid];
  }

  TreeNode* balanceBST(TreeNode* root) {
    vector<node*> values;
    flatten(root, values);
    return create(values, 0, values.size());
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
