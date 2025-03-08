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
    map<char, _node*> maps;
  } node;

  node* root;

  void add(int i, const string& s, node* current) {
    if (i == s.size())
      return;

    if (current->maps.contains(s[i])) {
      add(i + 1, s, current->maps[s[i]]);
    } else {
      node* temp = new node();
      temp->c = s[i];
      current->maps[s[i]] = temp;
      add(i + 1, s, temp);
    }
  }

  int walk(node* root, const string& s, int i) {
    if (not root or i == s.size())
      return 0;

    return 1 + walk(root->maps[s[i + 1]], s, i + 1);
  }

  int longestCommonPrefix(vector<int>& input_a, vector<int>& input_b) {
    node* root = new node();
    root->c = '@';

    for (int i : input_a)
      add(0, to_string(i), root);

    int answer = INT_MIN;
    for (int i : input_b) {
      string temp = to_string(i);
      int current = walk(root->maps[temp[0]], temp, 0);
      answer = max(answer, current);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
