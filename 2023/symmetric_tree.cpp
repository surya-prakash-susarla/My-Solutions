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
  static constexpr int minvalue = numeric_limits<int>::min();
  typedef TreeNode node;

  vector<vector<int>> get_trav(node* root) {
    queue<node*> current;
    current.push(root);

    vector<vector<int>> answer;

    while (not current.empty()) {
      queue<node*> next;
      vector<int> layer;
      while (not current.empty()) {
        node* temp = current.front();
        current.pop();
        if (temp) {
          layer.push_back(temp->val);
          next.push(temp->left);
          next.push(temp->right);
        } else {
          layer.push_back(minvalue);
          next.push(nullptr);
          next.push(nullptr);
        }
      }

      answer.emplace_back(layer);

      bool is_valid = false;
      for (queue<node*> temp = next; not temp.empty(); temp.pop())
        if (temp.front() != nullptr) {
          is_valid = true;
          break;
        }

      if (is_valid)
        swap(next, current);
    }

    return answer;
  }

  typedef vector<int> vint;
  typedef vector<vint> vvint;

  bool comp(vvint a, vvint b) {
    if (a.size() != b.size())
      return false;

    for (int i = 0; i < a.size(); i++) {
      reverse(b[i].begin(), b[i].end());
      if (a[i] != b[i])
        return false;
    }

    return true;
  }

  bool isSymmetric(TreeNode* root) {
    vector<vector<int>> left = get_trav(root->left);
    vector<vector<int>> right = get_trav(root->right);

    return comp(left, right);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
