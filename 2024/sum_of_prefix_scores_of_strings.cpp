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
    char c = '@';
    int count = 1;
    unordered_map<char, struct _node*> next;
    struct _node* get(char c) {
      if (next.contains(c))
        return next[c];
      else
        return nullptr;
    }
    void set(char c, struct _node* temp) { next[c] = temp; }
  } node;

  node* root;

  void add_word(node* root, const string& word, int index) {
    if (index == word.size())
      return;
    node* next = root->get(word[index]);
    if (next != nullptr) {
      next->count++;
      add_word(next, word, index + 1);
    } else {
      node* temp = new node();
      temp->c = word[index];
      root->set(word[index], temp);
      add_word(temp, word, index + 1);
    }
  }

  void search(node* root, const string& word, int index, int& answer) {
    if (index == word.size())
      return;
    node* temp = root->get(word[index]);
    if (temp) {
      answer += temp->count;
      search(temp, word, index + 1, answer);
    }
  }

  vector<int> sumPrefixScores(vector<string>& words) {
    root = new node();
    for (const string& i : words)
      add_word(root, i, 0);
    vector<int> answer(words.size(), 0);
    for (int i = 0; i < words.size(); i++)
      search(root, words[i], 0, answer[i]);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
