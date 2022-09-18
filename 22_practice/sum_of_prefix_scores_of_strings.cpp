#include <bits/stdc++.h>
using namespace std;

class trie {
 public:
  char current;
  map<char, trie*> children;
  int count = 0;

  trie* get_child(char c) {
    if (children[c] == nullptr) {
      children[c] = new trie();
      children[c]->current = c;
    }

    return children[c];
  }
};

void process_string(const string& value, map<char, trie*>& glob) {
  if (glob[value[0]] == nullptr) {
    trie* temp = new trie();
    temp->current = value[0];
    glob[value[0]] = temp;
  }

  trie* root = glob[value[0]];
  root->count++;

  for (int i = 1; i < value.size(); i++) {
    root = root->get_child(value[i]);
    root->count++;
  }
}

int get_count(const string& value, map<char, trie*>& glob) {
  trie* root = glob[value[0]];
  int answer = root->count;
  for (int i = 1; i < value.size(); i++) {
    root = root->get_child(value[i]);
    answer += root->count;
  }
  return answer;
}

class Solution {
 public:
  vector<int> sumPrefixScores(vector<string>& words) {
    map<char, trie*> glob;
    for (const string& i : words) {
      process_string(i, glob);
    }
    vector<int> answer(words.size());
    for (int i = 0; i < words.size(); i++) {
      answer[i] = get_count(words[i], glob);
    }
    return answer;
  }
};

int main() {
  return 0;
}
