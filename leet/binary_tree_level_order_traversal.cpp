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
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    typedef TreeNode tn;
    typedef vector<int> vint;
    typedef vector<vint> vvint;

    if (!root)
      return {};

    vvint answer;

    queue<tn*> current_level;
    queue<tn*> next_level;

    next_level.push(root);

    while (!next_level.empty()) {
      std::swap(current_level, next_level);

      vint current_level_values;
      while (!current_level.empty()) {
        tn* front = current_level.front();
        current_level_values.push_back(front->val);
        if (front->left)
          next_level.push(front->left);
        if (front->right)
          next_level.push(front->right);
        current_level.pop();
      }

      answer.push_back(current_level_values);
    }

    return answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
