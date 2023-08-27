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
  typedef vector<int> vint;

  node* __rec__(int left, int right, const vint& in, map<int, int>& post) {
    if (left > right)
      return nullptr;

    if (left == right)
      return new node(in[left]);

    int maxind = numeric_limits<int>::min();
    int cind = -1;

    for (int i = left; i <= right; i++) {
      if (post[in[i]] > maxind) {
        maxind = post[in[i]];
        cind = i;
      }
    }

    node* temp = new node(in[cind]);
    temp->left = __rec__(left, cind - 1, in, post);
    temp->right = __rec__(cind + 1, right, in, post);

    return temp;
  }

  TreeNode* buildTree(vector<int>& in, vector<int>& p) {
    map<int, int> post;
    for (int i = 0; i < p.size(); i++) {
      post[p[i]] = i;
    }
    return __rec__(0, in.size() - 1, in, post);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
