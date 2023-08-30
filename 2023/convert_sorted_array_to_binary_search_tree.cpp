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

  node* __rec__(int start, int end, const vector<int>& values) {
    if (start > end)
      return nullptr;
    if (start == end)
      return new node(values[start]);

    int mid = (start + end) / 2;
    node* temp = new node(values[mid]);

    temp->left = __rec__(start, mid - 1, values);
    temp->right = __rec__(mid + 1, end, values);

    return temp;
  }

  TreeNode* sortedArrayToBST(vector<int>& values) {
    return __rec__(0, values.size() - 1, values);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
