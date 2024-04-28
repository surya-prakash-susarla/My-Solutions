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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
 public:
  typedef TreeNode node;

  int findMatchingClosure(int starting_index, const string& input) {
    // NOTE: This should always be '('.
    int open = 1;
    for (int i = starting_index + 1; i < input.size(); i++) {
      switch (input[i]) {
        case '(':
          open++;
          break;
        case ')':
          open--;
          break;
      }
      if (open == 0)
        return i;
    }
    // NOTE: This should never happen.
    return -1;
  }

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (not root)
      return "()";
    else
      return "(" + to_string(root->val) + serialize(root->left) +
             serialize(root->right) + ")";
  }

  node* deserialize(int start, int end, const string& data) {
    if (end - start == 1)
      return nullptr;
    node* current = new node;

    int left_subtree_start = start;
    while (data[++left_subtree_start] != '(')
      ;

    string extracted_number =
        data.substr(start + 1, left_subtree_start - start - 1);
    current->val = stoi(extracted_number);
    int left_subtree_end = findMatchingClosure(left_subtree_start, data);
    current->left = deserialize(left_subtree_start, left_subtree_end, data);
    current->right = deserialize(left_subtree_end + 1, end - 1, data);

    return current;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    return deserialize(0, data.size() - 1, data);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
