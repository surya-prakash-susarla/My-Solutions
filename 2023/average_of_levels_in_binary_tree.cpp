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

  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> answer;
    queue<node*> current;
    current.push(root);
    while (not current.empty()) {
      long long int sumvalue = 0;
      int n = current.size();
      queue<node*> next;
      for (; not current.empty(); current.pop()) {
        node* temp = current.front();
        sumvalue += temp->val;
        if (temp->left)
          next.push(temp->left);
        if (temp->right)
          next.push(temp->right);
      }
      answer.push_back((double)sumvalue / n);
      swap(current, next);
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
