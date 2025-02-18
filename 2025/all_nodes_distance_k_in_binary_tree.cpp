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
  typedef vector<int> vint;
  typedef TreeNode node;

  node* target;
  int k;

  vint answer;

  int __rec__(node* root) {
    if (not root)
      return -1;

    if (root == target)
      return k - 1;

    int dist = __rec__(root->left);
    if (dist != -1) {
      if (dist == 0) {
        answer.push_back(root->val);
        return -1;
      } else {
        insert_at_distance(root->right, dist - 1);
        return dist - 1;
      }
    }

    dist = __rec__(root->right);
    if (dist != -1) {
      if (dist == 0) {
        answer.push_back(root->val);
        return -1;
      } else {
        insert_at_distance(root->left, dist - 1);
        return dist - 1;
      }
    }

    return -1;
  }

  void insert_at_distance(node* root, int dist) {
    if (not root)
      return;

    if (dist < 0)
      return;

    if (dist == 0) {
      answer.push_back(root->val);
      return;
    }

    insert_at_distance(root->left, dist - 1);
    insert_at_distance(root->right, dist - 1);
    return;
  }

  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    insert_at_distance(target, k);
    this->target = target;
    this->k = k;
    __rec__(root);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
