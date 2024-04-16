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
  TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    typedef TreeNode node;
    if (depth == 1) {
      node* head = new node(val);
      head->left = root;
      return head;
    }

    queue<node*> current;
    current.push(root);

    for (int d = 2; d < depth; d++) {
      queue<node*> next;
      while (not current.empty()) {
        node* temp = current.front();
        if (temp->left)
          next.push(temp->left);
        if (temp->right)
          next.push(temp->right);
        current.pop();
      }
      swap(current, next);
    }

    while (not current.empty()) {
      node* temp = current.front();
      node* tleft = new node(val);
      node* tright = new node(val);
      if (temp->left)
        tleft->left = temp->left;
      temp->left = tleft;
      if (temp->right)
        tright->right = temp->right;
      temp->right = tright;
      current.pop();
    }

    return root;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
