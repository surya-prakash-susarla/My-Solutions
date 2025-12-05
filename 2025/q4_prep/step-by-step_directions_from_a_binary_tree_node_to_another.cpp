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

  int start;
  int end;

  node* lca_node;

  pair<bool, bool> lca(node* root) {
    if (not root)
      return {false, false};

    pair<bool, bool> current = {false, false};
    if (root->val == start)
      current.first = true;
    if (root->val == end)
      current.second = true;

    pair<bool, bool> left = lca(root->left);
    pair<bool, bool> right = lca(root->right);

    current.first |= left.first | right.first;
    current.second |= left.second | right.second;

    if (current.first and current.second) {
      lca_node = root;
      return {false, false};
    }

    return current;
  }

  void find_path(node* root, int target, string& ref, string& answer) {
    if (not root)
      return;

    if (root->val == target) {
      answer = ref;
      return;
    }

    ref.push_back('L');
    find_path(root->left, target, ref, answer);
    ref.pop_back();

    ref.push_back('R');
    find_path(root->right, target, ref, answer);
    ref.pop_back();
  }

  string getDirections(TreeNode* root, int startValue, int destValue) {
    start = startValue;
    end = destValue;

    lca(root);

    cout << "lca node : " << lca_node->val << endl;

    string start_path;
    string end_path;
    string working_mem;

    find_path(lca_node, start, working_mem, start_path);
    find_path(lca_node, end, working_mem, end_path);

    string answer = string(start_path.size(), 'U') + end_path;
    return answer;
  }
};
