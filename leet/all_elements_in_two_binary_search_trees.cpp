#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

// Problem:

typedef long long int llint;
typedef long double ldouble;

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
struct TreeNode;

class Solution {
 public:
  using node = TreeNode;

  void __get_flat__(node* root, vector<int>& values) {
    if (root == nullptr)
      return;
    __get_flat__(root->left, values);
    values.emplace_back(root->val);
    __get_flat__(root->right, values);
    return;
  }

  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    using vint = vector<int>;
    vint first;
    __get_flat__(root1, first);
    vint second;
    __get_flat__(root2, second);
    vint answer;
    int i = 0;
    int j = 0;
    while (i < first.size() and j < second.size()) {
      if (first[i] < second[j]) {
        answer.push_back(first[i++]);
      } else if (second[j] < first[i]) {
        answer.push_back(second[j++]);
      } else {
        answer.push_back(first[i++]);
        answer.push_back(second[j++]);
      }
    }
    if (i < first.size()) {
      while (i < first.size())
        answer.push_back(first[i++]);
    } else if (j < second.size()) {
      while (j < second.size())
        answer.push_back(second[j++]);
    }

    return answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
