#include <bits/stdc++.h>
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
  vector<double> averageOfLevels(TreeNode* root) {
    typedef long long int llint;
    typedef long double ldouble;
    typedef TreeNode node;

    deque<node*> current;
    current.push_back(root);

    vector<double> answer;

    while (not current.empty()) {
      llint csum = 0;
      for (auto it = current.begin(); it != current.end(); it++)
        csum += (*it)->val;
      double temp_answer = csum / (double)(current.size());
      answer.push_back(temp_answer);

      deque<node*> next;
      while (not current.empty()) {
        node* head = current.front();
        if (head->left)
          next.push_back(head->left);
        if (head->right)
          next.push_back(head->right);
        current.pop_front();
      }
      current = move(next);
    }

    return answer;
  }
};

int main() {
  return 0;
}
