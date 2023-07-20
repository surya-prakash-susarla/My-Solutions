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
  typedef pair<bool, bool> pbool;

  node* answer = nullptr;

  pbool baseline = make_pair(false, false);
  pbool ac = make_pair(true, true);

  pbool __rec__(node* root, const node* a, const node* b) {
    pbool current = baseline;
    if (root == a)
      current.first = true;
    else if (root == b)
      current.second = true;

    pbool left = baseline;
    if (root->left) {
      left = __rec__(root->left, a, b);
    }

    pbool right = baseline;
    if (root->right) {
      right = __rec__(root->right, a, b);
    }

    pbool result = baseline;
    result.first = current.first or left.first or right.first;
    result.second = current.second or left.second or right.second;

    if (result == ac and answer == nullptr) {
      answer = root;
    }

    return result;
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr)
      return nullptr;

    __rec__(root, p, q);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
