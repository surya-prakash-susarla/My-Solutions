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
  int minDepth(TreeNode* root) {
    if (not root)
      return 0;

    typedef TreeNode node;

    queue<node*> nodes;
    nodes.push(root);
    int answer = 1;

    while (not nodes.empty()) {
      queue<node*> next;
      while (not nodes.empty()) {
        node* current = nodes.front();
        nodes.pop();
        if (not current->left and not current->right)
          return answer;
        if (current->left)
          next.push(current->left);
        if (current->right)
          next.push(current->right);
      }
      swap(next, nodes);
      answer++;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
