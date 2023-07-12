#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define null NULL

using namespace std;

class node {
public:
  char value;
  vector<pair<char, node *>> connections;

  node(char value) { this->value = value; }

  node *exists(char value) {
    for (int i = 0; i < this->connections.size(); i++)
      if (this->connections[i].first == value)
        return this->connections[i].second;
    return null;
  }

  node *insert(char value) {
    node *temp;
    temp = exists(value);
    if (temp != null)
      return temp;
    temp = new node(value);
    this->connections.push_back(make_pair(value, temp));
    return temp;
  }
};

void print_vector(vector<string> values) {
  for (int i = 0; i < values.size(); i++)
    cout << values[i] << endl;
  return;
}

vector<string> dfs(node *root) {
  vector<string> final_values;

  cout << "DFS Node : " << root->value << endl;

  if (root->connections.size() > 0) {
    for (int i = 0; i < root->connections.size(); i++) {
      vector<string> temp_values = dfs(root->connections[i].second);
      for (int i = 0; i < temp_values.size(); i++)
        final_values.push_back(temp_values[i]);
    }
    for (int i = 0; i < final_values.size(); i++)
      final_values[i] = root->value + final_values[i];
  } else {
    cout << "In else part since no connections exist " << endl;
    cout << "Current contents of final values are " << endl;
    print_vector(final_values);
    string temp(1, root->value);
    final_values.push_back(temp);
  }
  cout << "Returning from " << root->value << " contents : " << endl;
  print_vector(final_values);
  return final_values;
}

vector<string> find_strings(string prefix, node *root) {
  node *temp;
  temp = root;
  int index = 0;
  while (index < prefix.size()) {
    temp = temp->exists(prefix[index]);
    index++;
  }

  cout << "Current value of the node is " << temp->value << endl;
  cout << "The connections of the current node are " << endl;
  for (int i = 0; i < temp->connections.size(); i++)
    cout << temp->connections[i].first << "\t";
  cout << endl;

  vector<string> final_values = dfs(temp);

  for (int i = 0; i < final_values.size(); i++)
    final_values[i] = prefix + final_values[i];
  return final_values;
}

void printer(node *root) {
  cout << "Node : " << root->value << endl;
  cout << "Connections " << endl;
  for (int i = 0; i < root->connections.size(); i++)
    cout << root->connections[i].first << "\t";
  cout << endl;
  for (int i = 0; i < root->connections.size(); i++)
    printer(root->connections[i].second);
  return;
}

int main() {
  int n;
  cout << "Enter the number of strings" << endl;
  cin >> n;
  cout << "Enter the strings" << endl;
  vector<string> input_values;
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    input_values.push_back(temp);
  }
  cout << "Enter the prefix value " << endl;
  string prefix;
  cin >> prefix;
  cout << "Converting entered string to form trie " << endl;

  node *root;
  root = new node('@');

  for (int i = 0; i < input_values.size(); i++) {
    string temp = input_values[i];
    int index = 0;
    node *temper;
    temper = root;
    while (index < temp.size()) {
      temper = temper->insert(temp[index]);
      index++;
    }
  }

  cout << "The contents of the tree are " << endl;
  printer(root);

  vector<string> values = find_strings(prefix, root);
  cout << "the final values are " << endl;
  for (int i = 0; i < values.size(); i++)
    cout << values[i] << endl;
  return 0;
}