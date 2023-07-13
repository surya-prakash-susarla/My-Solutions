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
  typedef vector<int> vint;
  map<vint, node*> values;

  set<node*> answer;

  vint __rec__(node* root) {
    if (root == nullptr)
      return {numeric_limits<int>::min()};
    vint current;
    current.push_back(root->val);
    vint left = __rec__(root->left);
    vint right = __rec__(root->right);
    current.insert(current.end(), left.begin(), left.end());
    current.insert(current.end(), right.begin(), right.end());

    auto it = values.find(current);
    if (it != values.end()) {
      answer.insert(it->second);
    } else {
      values[current] = root;
    }

    return current;
  }

  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    __rec__(root);
    return vector<node*>(answer.begin(), answer.end());
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
