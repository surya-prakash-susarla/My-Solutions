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
  bool isEvenOddTree(TreeNode* root) {
    typedef TreeNode node;

    if (root == nullptr)
      return false;

    queue<node*> current;
    current.push(root);

    bool even = true;

    while (not current.empty()) {
      queue<node*> temp;

      int prev_value = even ? INT_MIN : INT_MAX;

      while (not current.empty()) {
        node* pres_node = current.front();
        int pres = pres_node->val;
        current.pop();

        if (even) {
          if (pres % 2 == 0 or pres <= prev_value)
            return false;
        } else {
          if (pres % 2 == 1 or pres >= prev_value)
            return false;
        }

        prev_value = pres;

        if (pres_node->left)
          temp.push(pres_node->left);
        if (pres_node->right)
          temp.push(pres_node->right);
      }

      even = not even;
      swap(current, temp);
    }

    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
