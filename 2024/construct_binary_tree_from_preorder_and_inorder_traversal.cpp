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

  pair<node*, int> __rec__(const vector<int>& pre,
                           const vector<int>& in,
                           int ps,
                           int pe,
                           int is,
                           int ie) {
    if (ps > pe or is > ie)
      return {nullptr, 0};

    if (is == ie) {
      node* current = new node(in[is]);
      return {current, 1};
    }

    node* current = new node(pre[ps]);

    int ind = -1;
    for (int i = is; i <= ie; i++)
      if (in[i] == pre[ps]) {
        ind = i;
        break;
      }

    pair<node*, int> left = __rec__(pre, in, ps + 1, pe, is, ind - 1);
    pair<node*, int> right =
        __rec__(pre, in, ps + left.second + 1, pe, ind + 1, ie);

    current->left = left.first;
    current->right = right.first;

    return {current, 1 + left.second + right.second};
  }

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    const int n = inorder.size();
    pair<node*, int> answer = __rec__(preorder, inorder, 0, n - 1, 0, n - 1);
    return answer.first;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
