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
  vector<tree_node *> children;
  bool has_children, has_parent;
  tree_node() {
    has_children = false;
    has_parent = false;
    cout << "init of tree_node" << endl;
  }
};

tree_node *root = null;
