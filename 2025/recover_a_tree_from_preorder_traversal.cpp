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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  typedef TreeNode node;

  TreeNode* recoverFromPreorder(string input) {
    int prev_depth = -1;
    int current_depth = 0;

    map<int, node*> depth_parent;

    // default node for anchor.
    depth_parent[-1] = new node(-1);

    for (int i = 0; i < input.size();) {
      if (input[i] == '-') {
        int j = i;
        while (j < input.size() and input[j] == '-') {
          j++;
        }
        current_depth = (j - i);
        i = j;
        // cout << "setting current depth to : " << current_depth << endl;
      } else {
        string nodeval;
        int j = i;
        while (j < input.size() and input[j] != '-') {
          nodeval += input[j];
          j++;
        }
        i = j;
        // cout << "prev depth : " << prev_depth << " , current depth : " <<
        // current_depth << endl; cout << "value of node : " << nodeval << endl;

        if (current_depth < prev_depth) {
          // cout << "erasing all depths equal to lower than current value" <<
          // endl;
          depth_parent.erase(depth_parent.find(current_depth),
                             depth_parent.end());
        }
        node* parent = depth_parent[current_depth - 1];
        // cout << "parent : " << parent->val << endl;
        node* new_node = new node(stoi(nodeval));

        if (parent->left == nullptr) {
          // cout << "inserting as left child of parent" << endl;
          parent->left = new_node;
        } else if (parent->right == nullptr) {
          // cout << "inserting as right child of parent" << endl;
          parent->right = new_node;
        } else {
          // cout << "error: both child already exist for parent : " << parent
          // << " , left : " << parent->left->val << " , right : " <<
          // parent->right->val << endl;
        }
        depth_parent[current_depth] = new_node;
        prev_depth = current_depth;
      }
    }

    return depth_parent[0];
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
