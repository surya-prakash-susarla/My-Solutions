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
  typedef Node node;

  Node* connect(Node* root) {
    if (not root)
      return root;

    queue<node*> current;
    current.push(root);

    while (not current.empty()) {
      queue<node*> next;
      node* prev = nullptr;
      for (; not current.empty(); current.pop()) {
        node* temp = current.front();
        if (prev) {
          prev->next = temp;
        }
        prev = temp;
        if (temp->left)
          next.push(temp->left);
        if (temp->right)
          next.push(temp->right);
      }
      swap(current, next);
    }

    return root;
  }
};
