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
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (not root)
      return {};

    typedef TreeNode node;

    queue<node*> current;
    vector<vector<int>> answer;

    current.push(root);
    while (not current.empty()) {
      queue<node*> next;
      vector<int> current_level;
      while (not current.empty()) {
        node* temp = current.front();
        current.pop();
        current_level.push_back(temp->val);
        if (temp->left)
          next.push(temp->left);
        if (temp->right)
          next.push(temp->right);
      }
      answer.emplace_back(current_level);
      swap(current, next);
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
