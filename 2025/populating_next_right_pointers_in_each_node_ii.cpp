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
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
 public:
  Node* connect(Node* root) {
    typedef Node node;
    if (not root)
      return nullptr;
    queue<node*> current;
    current.push(root);
    while (not current.empty()) {
      queue<node*> next;
      while (not current.empty()) {
        node* top = current.front();
        current.pop();
        top->next = (current.empty() ? nullptr : current.front());

        if (top->left)
          next.push(top->left);
        if (top->right)
          next.push(top->right);
      }
      swap(current, next);
    }
    return root;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
