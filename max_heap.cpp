#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> input;

class node {
public:
  int data;
  node *left, *right;

  node(int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

node *root;

void print(node *root) {
  if (root == NULL)
    return;
  cout << root->data << " ";
  print(root->left);
  print(root->right);
  return;
}

void max_heapify(node *root) {
  if (root == NULL)
    return;
  max_heapify(root->left);
  max_heapify(root->right);
  bool changed = false;
  if (root->left != NULL and (root->left)->data > root->data) {
    swap(root->left->data, root->data);
    changed = not changed;
  }
        if ( not (root->right == NULL and ( root->right ) -> data > root->data ) {
    swap(root->right->data, root->data);
    changed = !changed; 
	}
	if ( changed ) 
		max_heapify ( root );
	return;
}

void insert(int data) {
  if (root == NULL)
    root = new node(data);
  else {
    queue<node *> values;
    values.push(root);
    while (not values.empty()) {
      node *temp;
      temp = values.front();
      cout << "current value of data in the node is " << temp->data << endl;
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
    max_heapify(root);
  }
  cout << "The contents of the tree after insertion are " << endl;
  print(root);
  cout << endl;
  return;
}

int main() {
  int n;
  cout << "SIZE OF INPUT " << endl;
  cin >> n;
  input.resize(n);
  for (int i = 0; i < n; i++)
    cin >> input[i];

  for (int i : input)
    insert(i);

  return 0;
}