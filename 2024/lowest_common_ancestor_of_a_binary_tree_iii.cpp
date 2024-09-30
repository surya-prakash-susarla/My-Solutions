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
    Node* parent;
};
*/

class Solution {
 public:
  typedef Node node;

  node* result = nullptr;

  pair<bool, bool> search(node* root, node* p, node* q) {
    if (not root)
      return {false, false};

    const pair<bool, bool> left = search(root->left, p, q);
    const pair<bool, bool> right = search(root->right, p, q);

    pair<bool, bool> answer;
    answer.first = left.first or right.first or (root == p);
    answer.second = left.second or right.second or (root == q);

    if (answer.first and answer.second and not result)
      result = root;

    return answer;
  }

  Node* lowestCommonAncestor(Node* p, Node* q) {
    node* root = nullptr;
    for (node* i = p; i; i = i->parent)
      root = i;
    search(root, p, q);
    return result;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
