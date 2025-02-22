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

  node* __rec__(const vint& values, int start, int end) {
    if (start > end)
      return nullptr;

    node* current = new node(values[start]);

    int root = start;
    int right = end + 1;

    for (int i = start + 1; i <= end; i++) {
      if (values[i] > values[root]) {
        right = i;
        break;
      }
    }

    current->left = __rec__(values, root + 1, right - 1);
    current->right = __rec__(values, right, end);

    return current;
  }

  TreeNode* bstFromPreorder(vector<int>& input) {
    return __rec__(input, 0, input.size() - 1);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
