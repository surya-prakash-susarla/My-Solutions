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
  typedef struct _tnode {
    char c = '@';
    bool is_terminal = false;
    unordered_map<char, struct _tnode*> nmap;
  } tnode;

  tnode* root;

  void addWord(tnode* node, const string& s, int i) {
    if (i == s.size())
      return;

    if (node->nmap.contains(s[i])) {
      if (i == s.size() - 1)
        node->nmap[s[i]]->is_terminal = true;
      addWord(node->nmap[s[i]], s, i + 1);
    } else {
      tnode* temp = new tnode();
      temp->c = s[i];
      if (i == s.size() - 1)
        temp->is_terminal = true;
      node->nmap[s[i]] = temp;
      addWord(temp, s, i + 1);
    }
  }

  inline void createTrie(const vector<string>& dict) {
    for (const string& i : dict)
      addWord(root, i, 0);
  }

  set<int> moveIndex(int i, const string& s) {
    int oi = i;
    int length = 0;
    tnode* ref = root;
    set<int> answer;

    while (i < s.size()) {
      if (ref->is_terminal)
        answer.insert(oi + length);

      if (not ref->nmap.contains(s[i]))
        break;

      length++;
      ref = ref->nmap[s[i]];
      i++;
    }

    if (ref->is_terminal)
      answer.insert(oi + length);
    return answer;
  }

  unordered_map<int, int> memo;

  int __rec__(int i, const string& s) {
    if (memo.contains(i))
      return memo[i];

    if (i == s.size())
      return 0;

    int inc = INT_MAX;
    {
      set<int> ni = moveIndex(i, s);
      for (int i : ni)
        inc = min(inc, __rec__(i, s));
    }
    int exc = 1 + __rec__(i + 1, s);

    memo[i] = min(inc, exc);
    return memo[i];
  }

  int minExtraChar(string s, vector<string>& dictionary) {
    root = new tnode();
    createTrie(dictionary);
    return __rec__(0, s);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
