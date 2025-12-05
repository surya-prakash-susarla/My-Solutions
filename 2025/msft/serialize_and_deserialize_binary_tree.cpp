/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
 public:
  typedef TreeNode node;

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (not root)
      return "()";
    const string next = serialize(root->left) + serialize(root->right);
    const string answer = "(" + to_string(root->val) + next + ")";
    return answer;
  }

  node* __rec__(int i, int j, const string& data) {
    if (j - i == 1)
      return nullptr;

    int lopen = -1;
    for (int k = i + 1; k <= j; k++)
      if (data[k] == '(') {
        lopen = k;
        break;
      }
    int lend = -1;
    int c = 0;
    for (int k = lopen + 1; k <= j; k++)
      if (data[k] == ')') {
        if (c == 0) {
          lend = k;
          break;
        } else {
          c--;
        }
      } else if (data[k] == '(') {
        c++;
      }

    string num = data.substr(i + 1, lopen - i - 1);
    node* left = __rec__(lopen, lend, data);
    node* right = __rec__(lend + 1, j - 1, data);

    node* result = new node(stoi(num));
    result->left = left;
    result->right = right;
    return result;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    return __rec__(0, data.size() - 1, data);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
