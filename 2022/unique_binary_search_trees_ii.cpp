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
  typedef TreeNode node;
  typedef vector<node*> vnode;
  typedef vector<vnode> vvnode;
  typedef vector<vvnode> vvvnode;

  vector<TreeNode*> generateTrees(int n) {
    memo = vvvnode(n + 1, vvnode(n + 1));
    _init(n);
    return _calc(1, n);
  }

  vnode _calc(int start, int end) {
    if (start > end)
      return {};
    if (not memo[start][end].empty())
      return memo[start][end];

    vnode answer;
    for (int i = start; i <= end; i++) {
      vnode left = _calc(start, i - 1);
      vnode right = _calc(i + 1, end);
      vnode temp_answer = _combine_trees(i, left, right);
      answer.insert(answer.end(), temp_answer.begin(), temp_answer.end());
    }

    memo[start][end] = answer;
    return answer;
  }

  vnode _combine_trees(int main, const vnode left, const vnode right) {
    if (left.empty() and right.empty())
      return {new node(main)};
    vnode answer;
    if (left.empty())
      for (node* i : right)
        answer.push_back(new node(main, nullptr, i));
    else if (right.empty())
      for (node* i : left)
        answer.push_back(new node(main, i, nullptr));
    else
      for (node* i : left)
        for (node* j : right)
          answer.push_back(new node(main, i, j));
    return answer;
  }

  inline void _init(int n) {
    for (int i = 1; i <= n; i++)
      memo[i][i] = {new node(i)};
    return;
  }

  vvvnode memo;
};
