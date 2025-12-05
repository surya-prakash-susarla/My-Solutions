/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  typedef TreeNode node;

  vector<node*> answer;

  void down(node* root, int depth) {
    if (depth == 0) {
      answer.push_back(root);
      return;
    }
    if (not root)
      return;
    down(root->left, depth - 1);
    down(root->right, depth - 1);
  }

  int up(node* root, node* target, int k) {
    if (root == target)
      return k - 1;

    if (not root)
      return INT_MAX;

    int ldist = up(root->left, target, k);
    int rdist = up(root->right, target, k);

    if (ldist < 0)
      ldist = INT_MAX;
    if (rdist < 0)
      rdist = INT_MAX;

    if (ldist != INT_MAX) {
      if (ldist == 0)
        answer.push_back(root);
      else
        down(root->right, ldist - 1);
    } else if (rdist != INT_MAX) {
      if (rdist == 0)
        answer.push_back(root);
      else
        down(root->left, rdist - 1);
    }

    int depth = min(ldist, rdist);
    return depth == INT_MAX ? INT_MAX : depth - 1;
  }

  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    down(target, k);

    up(root, target, k);

    vector<int> values;
    for (auto i : answer)
      if (i)
        values.push_back(i->val);

    return values;
  }
};
