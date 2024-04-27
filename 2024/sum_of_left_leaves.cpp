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

  int sumOfLeftLeaves(TreeNode* root) {
    int answer = 0;
    queue<pair<node*, bool>> nodes;
    nodes.push(make_pair(root, false));
    while (not nodes.empty()) {
      queue<pair<node*, bool>> next_nodes;
      while (not nodes.empty()) {
        pair<node*, bool> current = nodes.front();
        nodes.pop();
        if (current.first->left or current.first->right) {
          if (current.first->left)
            next_nodes.push(make_pair(current.first->left, true));
          if (current.first->right)
            next_nodes.push(make_pair(current.first->right, false));
        } else if (current.second) {
          answer += current.first->val;
        }
      }
      swap(nodes, next_nodes);
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
