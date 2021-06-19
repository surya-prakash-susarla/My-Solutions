#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define null NULL
#define null_vector vector<char>()
using namespace std;

class tree_node {
public:
  char data;
  tree_node *left, *right;

  tree_node() {
    this->left = null;
    this->right = null;
  }
};

tree_node *binary_input(tree_node *value) {
  cout << "Enter data " << endl;
  value = new tree_node;
  cin >> value->data;
  char ch;
  cout << "do you want left node from " << value->data << endl;
  cin >> ch;
  if (ch == 'y')
    value->left = binary_input(value->left);
  cout << "do you want right node from " << value->data << endl;
  cin >> ch;
  if (ch == 'y')
    value->right = binary_input(value->right);
  return value;
}

void print_preorder(tree_node *root) {
  if (root == null)
    return;
  cout << root->data << endl;
  print_preorder(root->left);
  print_preorder(root->right);
  return;
}

vector<char> bfs_path(tree_node *root, char req, vector<char> current_path) {
  if (root == null)
    return null_vector;
  current_path.push_back(root->data);
  if (root->left != null and root->left->data == req)
    return current_path;
  else if (root->right != null and root->right->data == req)
    return current_path;

  vector<char> path1 = bfs_path(root->left, req, current_path);
  vector<char> path2 = bfs_path(root->right, req, current_path);

  if (path1 != null_vector)
    return path1;
  else if (path2 != null_vector)
    return path2;
  return null_vector;
}

void ancestor_finder(tree_node *root) {
  char a, b;
  cout << "Enter the node values" << endl;
  cin >> a >> b;
  vector<char> path_a = bfs_path(root, a, null_vector);
  vector<char> path_b = bfs_path(root, b, null_vector);
  cout << "Path of a is " << endl;
  for (int i = 0; i < path_a.size(); i++)
    cout << path_a[i] << endl;
  cout << "Path of b is " << endl;
  for (int i = 0; i < path_b.size(); i++)
    cout << path_b[i] << endl;
  int ina = 0, inb = 0;
  while (ina < path_a.size() and inb < path_b.size())
    if (path_a[ina++] != path_b[inb++])
      break;
  cout << "The common ancestor is at " << path_a[ina - 1] << endl;
  return;
}

int main() {
  cout << "START" << endl;
  tree_node *root;
  root = binary_input(root);
  cout << "DATA : " << endl;
  print_preorder(root);
  cout << "FUNCTION CALL : " << endl;
  ancestor_finder(root);
  cout << "END" << endl;
  return 0;
}