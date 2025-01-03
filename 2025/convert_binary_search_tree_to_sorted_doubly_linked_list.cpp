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

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
 public:
  typedef Node node;

  pair<node*, node*> __rec__(node* root) {
    node* left_end = nullptr;
    if (root->left) {
      pair<node*, node*> left = __rec__(root->left);
      left_end = left.first;
      left.second->right = root;
      root->left = left.second;
    } else {
      left_end = root;
    }

    node* right_end = nullptr;
    if (root->right) {
      pair<node*, node*> right = __rec__(root->right);
      right_end = right.second;
      right.first->left = root;
      root->right = right.first;
    } else {
      right_end = root;
    }

    return {left_end, right_end};
  }

  Node* treeToDoublyList(Node* root) {
    if (root == nullptr)
      return nullptr;

    pair<node*, node*> ends = __rec__(root);

    ends.first->left = ends.second;
    ends.second->right = ends.first;

    return ends.first;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
