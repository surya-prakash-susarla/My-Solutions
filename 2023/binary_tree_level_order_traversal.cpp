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
    if (root == nullptr)
      return {};

    typedef vector<int> vint;
    typedef vector<vint> vvint;
    typedef TreeNode node;

    queue<node*> current;
    current.push(root);

    vvint answer;

    while (not current.empty()) {
      vint current_answer;
      queue<node*> next;
      while (not current.empty()) {
        node* temp = current.front();
        current.pop();
        current_answer.push_back(temp->val);
        if (temp->left)
          next.push(temp->left);
        if (temp->right)
          next.push(temp->right);
      }
      swap(current, next);
      answer.emplace_back(current_answer);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
