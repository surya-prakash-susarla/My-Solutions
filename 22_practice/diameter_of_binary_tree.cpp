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

  int answer = numeric_limits<int>::min();

  int __rec__(node* head) {
    if (head == nullptr)
      return 0;
    int left = __rec__(head->left);
    int right = __rec__(head->right);

    answer = max(answer, left + right + 1);

    return max(left, right) + 1;
  }

  int diameterOfBinaryTree(TreeNode* root) {
    __rec__(root);
    return answer - 1;
  }
};
