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
  vector<int> largestValues(TreeNode* root) {
    if (root == nullptr)
      return {};
    typedef TreeNode node;
    vector<int> answer;
    queue<node*> layer;
    layer.push(root);
    while (not layer.empty()) {
      queue<node*> next_layer;
      int maxvalue = INT_MIN;
      while (not layer.empty()) {
        node* current = layer.front();
        maxvalue = max(maxvalue, current->val);
        if (current->left)
          next_layer.push(current->left);
        if (current->right)
          next_layer.push(current->right);
        layer.pop();
      }
      answer.push_back(maxvalue);
      swap(layer, next_layer);
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
