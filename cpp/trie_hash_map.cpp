#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define null NULL

using namespace std;

class node {
public:
  char value;
  map<char, node *> connections;

  node(char value) { this->value = value; }

  node *exists(char value) {
    if (this->connections.count(value) > 0)
      return this->connections.at(value);
    else
      return null;
  }

  node *insert(char value) {
    node *answer;
    answer = exists(value);
    if (answer != null)
      return answer;
    answer = new node(value);
    this->connections.insert(make_pair(value, answer));
    return answer;
  }
};

vector<string> dfs(node *root) {
  vector<string> values;
  if (root->connections.size() > 0) {
    for (map<char, node *>::iterator it = root->connections.begin();
         it != root->connections.end(); it++) {
      vector<string> temp_values = dfs(it->second);
      for (int i = 0; i < temp_values.size(); i++)
        values.push_back(temp_values[i]);
    }
    for (int i = 0; i < values.size(); i++)
      values[i] = root->value + values[i];
  } else {
    string temp(1, root->value);
    values.push_back(temp);
  }
  return values;
}

vector<string> find_strings(string prefix, node *root) {
  int index = 0;
  while (index < prefix.size()) {
    node *temp;
    temp = root->exists(prefix[index]);
    root = temp;
    index++;
  }
  vector<string> dfs_values = dfs(root);
  for (int i = 0; i < dfs_values.size(); i++)
    dfs_values[i] = prefix + dfs_values[i];
  return dfs_values;
}

void printer(node *root) {
  cout << "Node : " << root->value << endl;
  for (map<char, node *>::iterator it = root->connections.begin();
       it != root->connections.end(); it++)
    printer(it->second);
  return;
}

int main() {
  int n;
  cout << "Enter number of strings" << endl;
  cin >> n;
  vector<string> input_values;
  cout << "Enter string values" << endl;
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    input_values.push_back(temp);
  }
  string prefix;
  cout << "Enter the prefix string" << endl;
  cin >> prefix;

  node *root;
  root = new node('@');

  for (int i = 0; i < n; i++) {
    int index = 0;
    node *terminal;
    terminal = root;
    while (index < input_values[i].size()) {
      node *temp_value;
      temp_value = terminal->insert(input_values[i][index]);
      terminal = temp_value;
      index++;
    }
  }

  // cout<<"The contained values are "<<endl;
  // printer ( root );

  vector<string> final_values = find_strings(prefix, root);
  cout << "The possible string values are " << endl;
  for (int i = 0; i < final_values.size(); i++)
    cout << final_values[i] << endl;
  return 0;
}
