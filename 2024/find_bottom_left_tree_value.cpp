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
  int findBottomLeftValue(TreeNode* root) {
    typedef TreeNode node;

    if (root == nullptr)
      return -1;

    queue<node*> current;
    current.push(root);

    node* left = nullptr;

    while (not current.empty()) {
      queue<node*> temp;
      left = current.front();
      while (not current.empty()) {
        node* top = current.front();
        current.pop();
        if (top->left)
          temp.push(top->left);
        if (top->right)
          temp.push(top->right);
      }
      swap(current, temp);
    }

    return left->val;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
