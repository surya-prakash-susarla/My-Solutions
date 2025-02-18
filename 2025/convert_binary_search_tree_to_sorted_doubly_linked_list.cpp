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

  pair<node*, node*> trav(node* root) {
    if (root == nullptr)
      return {nullptr, nullptr};

    pair<node*, node*> answer = {root, root};

    if (root->left) {
      pair<node*, node*> left = trav(root->left);
      answer.first = left.first;
      left.second->right = root;
      root->left = left.second;
    }
    if (root->right) {
      pair<node*, node*> right = trav(root->right);
      answer.second = right.second;
      right.first->left = root;
      root->right = right.first;
    }

    return answer;
  }

  Node* treeToDoublyList(Node* root) {
    if (not root)
      return nullptr;

    pair<node*, node*> answer = trav(root);
    answer.first->left = answer.second;
    answer.second->right = answer.first;
    return answer.first;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
