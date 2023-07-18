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
    if (root == nullptr)
      return nullptr;

    typedef Node node;

    for (queue<node*> current({root}); not current.empty();) {
      node* prev = nullptr;
      queue<node*> next;
      for (; not current.empty();) {
        node* top = current.front();
        current.pop();
        if (prev)
          prev->next = top;
        prev = top;
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
