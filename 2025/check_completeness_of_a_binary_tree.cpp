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

  bool isCompleteTree(TreeNode* root) {
    if (root == nullptr)
      return true;

    queue<node*> values;
    values.push(root);

    while (not values.empty()) {
      queue<node*> next;

      bool is_broken_node_found = false;
      while (not values.empty()) {
        node* current = values.front();
        values.pop();

        if (is_broken_node_found) {
          if (current->left or current->right)
            return false;
        } else {
          if (current->left) {
            next.push(current->left);
          } else {
            is_broken_node_found = true;
          }

          if (is_broken_node_found and current->right) {
            return false;
          }

          if (current->right) {
            next.push(current->right);
          } else {
            is_broken_node_found = true;
          }
        }
      }

      if (is_broken_node_found) {
        while (not next.empty()) {
          node* current = next.front();
          next.pop();
          if (current->left or current->right)
            return false;
        }
        return true;
      }

      swap(values, next);
    }

    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
