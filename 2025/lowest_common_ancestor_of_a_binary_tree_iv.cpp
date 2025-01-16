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

  node* answer = nullptr;

  int __rec__(node* root, const set<TreeNode*>& nodes) {
    if (root == nullptr)
      return 0;

    int total_found = 0;
    total_found += __rec__(root->left, nodes);
    total_found += __rec__(root->right, nodes);

    if (nodes.contains(root))
      total_found++;

    if (answer == nullptr and total_found == nodes.size()) {
      answer = root;
      return total_found;
    }

    return total_found;
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*>& nodes) {
    __rec__(root, set<node*>(nodes.begin(), nodes.end()));
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
