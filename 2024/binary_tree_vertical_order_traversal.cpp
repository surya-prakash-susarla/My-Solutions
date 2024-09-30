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
  map<int, vector<int>> values;

  typedef TreeNode node;

  void __bfs__(node* root) {
    typedef pair<node*, int> pint;
    queue<pint> nodes;
    nodes.push({root, 0});
    while (not nodes.empty()) {
      queue<pint> next;
      while (not nodes.empty()) {
        pint temp = nodes.front();
        nodes.pop();
        values[temp.second].push_back(temp.first->val);
        if (temp.first->left) {
          next.push({temp.first->left, temp.second - 1});
        }
        if (temp.first->right) {
          next.push({temp.first->right, temp.second + 1});
        }
      }
      swap(nodes, next);
    }
  }

  vector<vector<int>> verticalOrder(TreeNode* root) {
    if (not root)
      return {};
    __bfs__(root);

    vector<vector<int>> answer;
    for (auto it : values)
      answer.emplace_back(it.second);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
