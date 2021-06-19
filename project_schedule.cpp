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

tree_node *find_node(char value, vector<tree_node *> nodes) {
  cout << "searhcing value " << value << endl;
  for (int i = 0; i < nodes.size(); i++)
    if (nodes[i]->data == value)
      return nodes[i];
  cout << "WARNING : node not found in the vector" << endl;
  return null;
}

void print_path(vector<tree_node *> nodes) {
  vector<char> path;
  vector<bool> covered(nodes.size(), false);
  bool all_covered = false;
  while (not all_covered) {
    for (int i = 0; i < nodes.size(); i++)
      if (not covered[i] and not nodes[i]->has_children) {
        path.push_back(nodes[i]->data);
        covered[i] = true;
        for (int j = 0; j < nodes.size(); j++) {
          if (i != j and
              find(nodes[j]->children.begin(), nodes[j]->children.end(),
                   nodes[i]) != nodes[j]->children.end())
            nodes[j]->children.erase(nodes[j]->children.begin() +
                                     (find(nodes[j]->children.begin(),
                                           nodes[j]->children.end(), nodes[i]) -
                                      nodes[j]->children.begin()));
          if ((int)nodes[j]->children.size() == 0)
            nodes[j]->has_children = false;
        }
      }
    all_covered = true;
    for (int i = 0; i < covered.size(); i++)
      if (not covered[i]) {
        all_covered = false;
        break;
      }
  }
  cout << "the path is " << endl;
  for (int i = 0; i < path.size(); i++)
    cout << path[i] << endl;
  return;
}

void input() {
  cout << "Enter the number of projects" << endl;
  int proj;
  cin >> proj;
  vector<tree_node *> nodes;
  cout << "Enter the nodes" << endl;
  for (int i = 0; i < proj; i++) {
    char temp;
    cin >> temp;
    tree_node *temp_node;
    temp_node = new tree_node;
    temp_node->data = temp;
    cout << "pushing node " << temp_node->data << endl;
    nodes.push_back(temp_node);
  }
  cout << "Enter the number of dependencies" << endl;
  int dependencies;
  cin >> dependencies;
  cout << "Enter the dependencies" << endl;
  for (int i = 0; i < dependencies; i++) {
    char a, b;
    cin >> a >> b;
    tree_node *node_1 = find_node(a, nodes);
    tree_node *node_2 = find_node(b, nodes);
    node_2->children.push_back(node_1);
    node_2->has_children = true;
    node_1->has_parent = true;
  }
  print_path(nodes);
  cout << "returning from the input function" << endl;
  return;
}

int main() {
  cout << "starting the problem" << endl;
  input();
  cout << "terminating program" << endl;
  return 0;
}