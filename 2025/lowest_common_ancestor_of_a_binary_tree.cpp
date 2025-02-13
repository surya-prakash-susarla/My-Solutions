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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  typedef TreeNode node;

  node* answer = nullptr;

  typedef pair<bool, bool> pbool;

  pbool __rec__(node* root, node* l, node* r) {
    if (not root)
      return {false, false};

    pbool result = make_pair(root == l, root == r);

    pbool left = __rec__(root->left, l, r);
    result.first |= left.first;
    result.second |= left.second;

    pbool right = __rec__(root->right, l, r);
    result.first |= right.first;
    result.second |= right.second;

    if (not answer and result.first and result.second) {
      answer = root;
    }
    return result;
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    __rec__(root, p, q);

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
