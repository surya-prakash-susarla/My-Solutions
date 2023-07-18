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

  int answer = 0;

  void __rec__(node* root, int current) {
    int answer = (current * 10) + root->val;
    bool le = false;
    bool re = false;
    if (root->left) {
      le = true;
      __rec__(root->left, answer);
    }
    if (root->right) {
      re = true;
      __rec__(root->right, answer);
    }
    if (not le and not re) {
      this->answer += answer;
    }
  }

  int sumNumbers(TreeNode* root) {
    if (root == nullptr)
      return 0;
    __rec__(root, 0);
    return this->answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
