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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (root == nullptr)
      return {};

    typedef vector<int> vint;
    typedef vector<vint> vvint;
    typedef TreeNode node;

    vvint answer;
    deque<node*> current;
    bool direction = true;

    current.push_front(root);
    while (not current.empty()) {
      vint current_answer;
      deque<node*> next;
      if (direction) {
        for (; not current.empty(); current.pop_front()) {
          node* temp = current.front();
          current_answer.push_back(temp->val);
          if (temp->left)
            next.push_back(temp->left);
          if (temp->right)
            next.push_back(temp->right);
        }
      } else {
        for (; not current.empty(); current.pop_back()) {
          node* temp = current.back();
          current_answer.push_back(temp->val);
          if (temp->right)
            next.push_front(temp->right);
          if (temp->left)
            next.push_front(temp->left);
        }
      }
      answer.emplace_back(current_answer);
      direction = not direction;
      swap(current, next);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
