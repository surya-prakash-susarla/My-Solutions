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

  int maxvalue = numeric_limits<int>::min();

  optional<int> __rec__(node* head) {
    optional<int> left_value = head->left ? __rec__(head->left) : nullopt;
    optional<int> right_value = head->right ? __rec__(head->right) : nullopt;

    // propagate upwards
    int answer = head->val;

    // dead end with current node;
    if (left_value.has_value()) {
      maxvalue = max(maxvalue, left_value.value());
      answer = max(answer, head->val + left_value.value());
    }
    if (right_value.has_value()) {
      maxvalue = max(maxvalue, right_value.value());
      answer = max(answer, head->val + right_value.value());
    }
    maxvalue = max(maxvalue, head->val);
    if (left_value.has_value() and right_value.has_value())
      maxvalue =
          max(maxvalue, head->val + left_value.value() + right_value.value());
    return answer;
  }

  int maxPathSum(TreeNode* root) {
    if (root == nullptr)
      return 0;
    optional<int> temp = __rec__(root);
    maxvalue = max(maxvalue, temp.value());
    return maxvalue;
  }
};
