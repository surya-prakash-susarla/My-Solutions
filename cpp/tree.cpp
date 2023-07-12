#include <iostream>

using namespace std;

class tree_node {
public:
  int data;
  tree_node *left, *right;
};

tree_node *root;

tree_node *create_nodes(tree_node *root) {
  root = new tree_node;
  int n;
  cout << "enter any number " << endl;
  cin >> n;
  root->data = n;
  char c;
  cout << "do you want to create left node for " << n << endl;
  cin >> c;
  if (c == 'y')
    root->left = create_nodes(root->left);
  else
    root->left = NULL;
  cout << "do you want to create right node for " << n << endl;
  cin >> c;
  if (c == 'y')
    root->right = create_nodes(root->right);
  else
    root->right = NULL;
  return root;
}

void printer(tree_node *starter) {
  if (starter == NULL)
    return;
  cout << starter->data << endl;
  printer(starter->left);
  printer(starter->right);
  return;
}

int main() {
  root = create_nodes(root);
  cout << "the data in the root is " << root->data << endl;
  printer(root);
  return 0;
}
