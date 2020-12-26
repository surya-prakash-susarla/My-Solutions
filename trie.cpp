#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Trie {
 private:
  class TrieNode {
   public:
    char value;
    vector<TrieNode*> links;
    bool end_node;

    TrieNode(char c) {
      this->value = c;
      this->end_node = true;
    }

    TrieNode* indexOf(char c) {
      for (TrieNode* temp : this->links)
        if (temp->value == c)
          return temp;
      return NULL;
    }

    TrieNode* insert(char c) {
      this->end_node = false;
      TrieNode* prev_node = indexOf(c);
      if (prev_node != NULL)
        return prev_node;
      TrieNode* new_node = new TrieNode(c);
      this->links.push_back(new_node);
      return new_node;
    }
  };

  TrieNode* root;

  void formStrings(TrieNode* iter,
                   string current_value,
                   vector<string>& values) {
    current_value += iter->value;
    if (iter->end_node) {
      values.push_back(current_value.substr(1));
      return;
    }
    for (int i = 0; i < iter->links.size(); i++)
      formStrings(iter->links[i], current_value, values);
  }

 public:
  Trie() { this->root = new TrieNode('@'); }

  vector<string> getStrings() {
    vector<string> values;
    formStrings(this->root, "", values);
    return values;
  }

  void makeTree(string value) {
    TrieNode* iter = this->root;
    for (int i = 0; i < value.size(); i++)
      iter = iter->insert(value[i]);
    return;
  }
};

int main() {
  Trie trie;
  for (int i = 0; i < 4; i++) {
    string temp;
    cin >> temp;
    trie.makeTree(temp);
  }
  cout << "String after recon are " << endl;
  vector<string> values = trie.getStrings();

  for (string temp : values)
    cout << temp << endl;

  return 0;
}
