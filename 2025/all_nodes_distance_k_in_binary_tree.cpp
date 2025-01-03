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
  vector<int> answer;

  typedef TreeNode node;

  void __down_rec__(node* root, int depth) {
    if (root == nullptr)
      return;
    if (depth == 0) {
      answer.push_back(root->val);
      return;
    } else {
      __down_rec__(root->left, depth - 1);
      __down_rec__(root->right, depth - 1);
    }
  }

  int __up_rec__(node* root, const node* target, const int depth) {
    if (root == nullptr)
      return INT_MAX;

    if (root == target) {
      return 1;
    }

    const int ld = __up_rec__(root->left, target, depth);
    if (ld != INT_MAX) {
      if (ld == depth) {
        answer.push_back(root->val);
        return INT_MAX;
      } else {
        __down_rec__(root->right, depth - ld - 1);
        return ld + 1;
      }
    }

    const int rd = __up_rec__(root->right, target, depth);
    if (rd != INT_MAX) {
      if (rd == depth) {
        answer.push_back(root->val);
        return INT_MAX;
      } else {
        __down_rec__(root->left, depth - rd - 1);
        return rd + 1;
      }
    }
    return INT_MAX;
  }

  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    __down_rec__(target, k);
    __up_rec__(root, target, k);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
