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

  int answer;
  int k;

  int __rec__(node* root, int base) {
    if (root->left) {
      base = __rec__(root->left, base);
    }
    base++;
    if (base == k) {
      answer = root->val;
    }
    if (root->right) {
      base = __rec__(root->right, base);
    }
    return base;
  }

  int kthSmallest(TreeNode* root, int k) {
    if (not root)
      return 0;
    this->k = k;
    __rec__(root, 0);

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
