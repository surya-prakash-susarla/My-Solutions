#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define node TreeNode

pair<node*, node*> calc(queue<int>, queue<int>);

node* findChild(queue<int>& pre_q, queue<int>& post_q) {
  if (pre_q.size() == 0 or post_q.size() == 0)
    return NULL;

  queue<int> pre_child_values, post_child_values;
  node* current_node = new node(pre_q.front());
  pre_q.pop();

  while (post_q.front() != current_node->val) {
    post_child_values.push(post_q.front());
    pre_child_values.push(pre_q.front());
    post_q.pop();
    pre_q.pop();
  }

  post_q.pop();

  pair<node*, node*> ret_values = calc(pre_child_values, post_child_values);
  current_node->left = ret_values.first,
  current_node->right = ret_values.second;

  return current_node;
}

pair<node*, node*> calc(queue<int> pre_q, queue<int> post_q) {
  if (pre_q.size() == 0 or post_q.size() == 0)
    return pair<node*, node*>(NULL, NULL);

  node* left_root = findChild(pre_q, post_q);
  node* right_root = findChild(pre_q, post_q);

  return pair<node*, node*>(left_root, right_root);
}

class Solution {
 public:
  TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    queue<int> pre_q, post_q;
    for (int i = 1; i < pre.size(); i++)
      pre_q.push(pre[i]);
    for (int i = 0; i < post.size() - 1; i++)
      post_q.push(post[i]);
    node* root = new node(pre[0]);
    pair<node*, node*> ret_values = calc(pre_q, post_q);
    root->left = ret_values.first, root->right = ret_values.second;
    return root;
  }
};