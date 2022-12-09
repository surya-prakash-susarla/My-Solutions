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

  int maxvalue = numeric_limits<int>::min();

  vector<int> __rec__(node* root) {
    if (root == nullptr)
      return {};

    vector<int> left = __rec__(root->left);
    vector<int> right = __rec__(root->right);

    vector<int> temp = left;
    temp.insert(temp.end(), right.begin(), right.end());

    for (int i : temp) {
      maxvalue = max(maxvalue, abs(root->val - i));
    }

    temp.push_back(root->val);
    return temp;
  }

  int maxAncestorDiff(TreeNode* root) {
    __rec__(root);

    return maxvalue;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
