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
  typedef vector<int> vint;
  typedef vector<vint> vvint;
  typedef pair<int, int> pint;
  typedef TreeNode node;

  map<int, vector<pint>> output;

  void __rec__(node* root, int row, int col) {
    if (root == nullptr)
      return;

    output[col].push_back({row, root->val});

    __rec__(root->left, row + 1, col - 1);
    __rec__(root->right, row + 1, col + 1);
  }

  vector<vector<int>> verticalTraversal(TreeNode* root) {
    __rec__(root, 0, 0);

    vvint answer;
    for (auto i : output) {
      vector<pint> temp = i.second;
      sort(temp.begin(), temp.end(), [](const pint& a, const pint& b) {
        if (a.first == b.first)
          return a.second < b.second;
        return a.first < b.first;
      });
      vint temp2;
      for (auto j : temp)
        temp2.push_back(j.second);
      answer.emplace_back(temp2);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
