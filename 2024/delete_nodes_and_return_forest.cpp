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

  vector<node*> answer;
  set<int> target;

  // Return value indicates if the connection to child should be removed.
  bool __rec__(node* current, bool is_root = false) {
    if (not current)
      return false;

    if (target.find(current->val) == target.end()) {
      bool result = __rec__(current->left, false);
      if (result)
        current->left = nullptr;
      result = __rec__(current->right, false);
      if (result)
        current->right = nullptr;
      if (is_root)
        answer.push_back(current);
      return false;
    } else {
      __rec__(current->left, true);
      __rec__(current->right, true);
      return true;
    }
  }

  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    target = set<int>(to_delete.begin(), to_delete.end());
    __rec__(root, true);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
