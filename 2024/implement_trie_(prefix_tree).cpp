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

class Trie {
 public:
  typedef struct _node {
    char c = '@';
    bool end_exists = false;
    map<char, _node> cons;
  } node;

  node root;

  Trie() {
    root.c = '@';
    root.end_exists = true;
  }

  void insert(int index, node& ref, const string& word) {
    if (index == word.size()) {
      ref.end_exists = true;
      return;
    }

    auto it = ref.cons.find(word[index]);
    if (it == ref.cons.end()) {
      node temp;
      temp.c = word[index];
      ref.cons[word[index]] = temp;
      insert(index + 1, ref.cons[word[index]], word);
    } else {
      insert(index + 1, it->second, word);
    }
  }

  void insert(string word) { insert(0, root, word); }

  bool search(int index,
              node& ref,
              const string& word,
              bool exact_match = true) {
    if (index == word.size())
      return exact_match ? ref.end_exists : true;

    auto it = ref.cons.find(word[index]);
    if (it == ref.cons.end())
      return false;

    return search(index + 1, it->second, word, exact_match);
  }

  bool search(string word) { return search(0, root, word); }

  bool startsWith(string prefix) { return search(0, root, prefix, false); }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
