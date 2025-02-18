#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

typedef long long int llint;
typedef long long unsigned int ullint;

using namespace std;

class Solution {
 public:
  typedef struct _node {
    char c;
    bool is_end;
    map<char, _node*> values;

    _node* get(char c) {
      if (values.contains(c))
        return values[c];

      _node* temp = new _node();
      temp->c = c;
      temp->is_end = false;
      values[c] = temp;
      return temp;
    }
  } node;

  void make(node* root, string s) {
    for (int i = 0; i < s.size(); i++) {
      node* current = root->get(s[i]);
      if (i == s.size() - 1)
        current->is_end = true;

      root = current;
    }
  }

  void print_trie(node* root) {
    if (not root)
      return;
    cout << "root : " << root->c << " , is end : " << root->is_end
         << " , children size : " << root->values.size() << endl;
    cout << "children : ";
    for (auto i : root->values)
      cout << i.first << " ";
    cout << endl;
    for (auto i : root->values)
      print_trie(i.second);
  }

  map<pair<int, node*>, bool> memo;

  node* orig_root;

  bool search(int index, const string& input, node* root) {
    if (index == input.size()) {
      return root->is_end;
    }

    if (not root)
      return false;

    {
      auto it = memo.find(make_pair(index, root));
      if (it != memo.end())
        return it->second;
    }

    bool result = false;
    if (root->is_end) {
      result = search(index, input, orig_root);
    }

    result |= search(index + 1, input, root->get(input[index]));

    memo[make_pair(index, root)] = result;
    return result;
  }

  bool wordBreak(string s, vector<string>& input) {
    node* root = new node();
    orig_root = root;
    root->c = '@';
    root->is_end = false;
    for (const string& i : input)
      make(root, i);

    // cout << "trie made" << endl;
    // print_trie(root);

    return search(0, s, root);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
