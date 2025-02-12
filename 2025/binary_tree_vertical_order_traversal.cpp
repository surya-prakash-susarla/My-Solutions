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

  vector<vector<int>> verticalOrder(TreeNode* root) {
    if (not root)
      return {};

    vector<vector<int>> answer;

    map<int, vector<int>> values;

    queue<pair<node*, int>> current;
    current.push({root, 0});

    while (not current.empty()) {
      queue<pair<node*, int>> next;

      while (not current.empty()) {
        pair<node*, int> top = current.front();
        current.pop();

        values[top.second].push_back(top.first->val);
        if (top.first->left)
          next.push({top.first->left, top.second - 1});
        if (top.first->right)
          next.push({top.first->right, top.second + 1});
      }

      swap(next, current);
    }

    for (auto i : values)
      answer.emplace_back(i.second);

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
