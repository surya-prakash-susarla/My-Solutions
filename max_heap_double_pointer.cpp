#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class node {
public:
  int data;
  node *left, *right;

  node(int data) {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

void print(node *root) {
  if (root == NULL)
    return;
  cout << root->data << " ";
  print(root->left);
  print(root->right);
  return;
}

void swap(int &a, int &b) {
  int temp = b;
  b = a;
  a = temp;
  return;
}

void max_heapify(node *root) {
  if (root == NULL)
    return;
  max_heapify(root->left);
  max_heapify(root->right);
  bool changed = false;
  if (root->left != NULL and root->left->data > root->data) {
    swap(root->left->data, root->data);
    changed = true;
  }
  if (root->right != NULL and root->right->data > root->data) {
    swap(root->right->data, root->data);
    changed = true;
  }
  if (changed)
    max_heapify(root);
  return;
}

void insert(int data, node **root) {
  cout << " inserting " << data << endl;
  if (*root == NULL)
    *root = new node(data);
  else {
    queue<node *> values;
    values.push(*root);
    while (not values.empty()) {
      node *temp;
      temp = values.front();
      values.pop();
      if (temp->left == NULL) {
        temp->left = new node(data);
        break;
      }
      if (temp->right == NULL) {
        temp->right = new node(data);
        break;
      }
      values.push(temp->left);
      values.push(temp->right);
    }
    max_heapify(*root);
  }
  cout << "The tree after inserting is " << endl;
  print(*root);
  cout << endl;
  return;
}

int main() {
  int n;
  cout << "INPUT SIZE " << endl;
  cin >> n;
  cout << "INPUT" << endl;
  vector<int> input(n);
  for (int i = 0; i < n; i++)
    cin >> input[i];
  node *root;
  for (int i : input)
    insert(i, &root);
  cout << "processing complete printing elements " << endl;
  print(root);
  cout << endl;
  return 0;
}