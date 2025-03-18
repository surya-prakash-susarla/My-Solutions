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

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (not root)
      return "()";
    return "(" + to_string(root->val) + serialize(root->left) +
           serialize(root->right) + ")";
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data[1] == ')')
      return nullptr;

    int lb = 1;
    while (data[lb] != '(')
      lb++;
    int rb = lb;
    int count = 0;
    for (int i = rb; i < data.size(); i++) {
      if (data[i] == '(') {
        count++;
      } else if (data[i] == ')') {
        count--;
        if (count == 0) {
          rb = i;
          break;
        }
      }
    }

    const int val = stoi(data.substr(1, lb - 1));
    const string left = data.substr(lb, rb - lb + 1);
    const string right = data.substr(rb + 1, data.size() - rb - 2);

    node* temp = new node(val);
    temp->left = deserialize(left);
    temp->right = deserialize(right);
    return temp;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
