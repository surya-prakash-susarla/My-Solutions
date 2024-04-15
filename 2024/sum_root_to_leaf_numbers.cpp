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
  int answer = 0;

  typedef TreeNode node;

  inline void add_to_ans(const vector<char>& values) {
    string temp(values.begin(), values.end());
    answer += stoi(temp);
  }

  void __rec__(node* root, vector<char> values) {
    char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char aChar = digits[root->val];
    values.push_back(aChar);
    if (root->left == nullptr and root->right == nullptr) {
      add_to_ans(values);
      return;
    }
    if (root->left)
      __rec__(root->left, values);
    if (root->right)
      __rec__(root->right, values);
    return;
  }

  int sumNumbers(TreeNode* root) {
    if (root == nullptr)
      return 0;
    __rec__(root, {});
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
