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
  typedef deque<node*> qnode;

  void reverse_children(qnode parent, qnode children) {
    while (not parent.empty() and not children.empty()) {
      node* temp = parent.front();
      temp->left = children.back();
      children.pop_back();
      temp->right = children.back();
      children.pop_back();
      parent.pop_front();
    }
  }

  TreeNode* reverseOddLevels(TreeNode* root) {
    int level = 0;
    qnode current = {root};

    while (not current.empty()) {
      // cout << "leveL : " << level << endl;
      if (level++ % 2 == 0) {
        qnode next;
        qnode temp = current;

        while (not temp.empty()) {
          node* first = temp.front();
          if (first->left)
            next.push_back(first->left);

          if (first->right)
            next.push_back(first->right);

          first->left = nullptr;
          first->right = nullptr;

          temp.pop_front();
        }

        qnode next_children;
        temp = next;
        while (not temp.empty()) {
          node* temp_node = temp.front();

          if (temp_node->left)
            next_children.push_back(temp_node->left);

          if (temp_node->right)
            next_children.push_back(temp_node->right);

          temp.pop_front();
        }

        reverse_children(current, next);

        current = next;

        while (not next.empty() and not next_children.empty()) {
          node* temp_node = next.back();
          temp_node->left = next_children.front();
          next_children.pop_front();
          temp_node->right = next_children.front();
          next_children.pop_front();
          next.pop_back();
        }

      } else {
        qnode next;
        // cout << "in odd level" << endl;
        while (not current.empty()) {
          node* temp_node = current.front();

          if (temp_node->left) {
            // cout << "left node exists ? " << endl;
            // cout << temp_node->left->val << endl;
            next.push_back(temp_node->left);
          }

          if (temp_node->right) {
            // cout << "right node exists ? " << endl;
            // cout << temp_node->right->val << endl;
            next.push_back(temp_node->right);
          }

          current.pop_front();
        }
        // cout << "at level : " << level - 1 << endl;
        // cout << "size of next : " << next.size() << endl;
        current = next;
      }
    }

    return root;
  }
};

int main() {
  return 0;
}
