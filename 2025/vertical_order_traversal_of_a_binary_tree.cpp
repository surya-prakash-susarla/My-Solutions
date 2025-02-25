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

  map<int, vector<pair<int, int>>> values;

  void __rec__(node* root, int i, int j) {
    if (not root)
      return;

    values[j].push_back({i, root->val});

    __rec__(root->left, i + 1, j - 1);
    __rec__(root->right, i + 1, j + 1);
  }

  vector<vector<int>> verticalTraversal(TreeNode* root) {
    __rec__(root, 0, 0);

    typedef vector<int> vint;
    vector<vint> answer;

    for (auto i : values) {
      sort(i.second.begin(), i.second.end(),
           [](const pair<int, int>& a, const pair<int, int>& b) {
             if (a.first == b.first)
               return a.second < b.second;
             return a.first < b.first;
           });

      vint current;
      for (auto j : i.second)
        current.push_back(j.second);

      answer.emplace_back(current);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
