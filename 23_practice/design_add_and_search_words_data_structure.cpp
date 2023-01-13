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

class temp_value {
 public:
  temp_value() = default;

  map<char, temp_value*> values;

  void add_word(const string& word, int index) {
    if (index == word.size()) {
      values['@'] = nullptr;
      return;
    }
    auto it = values.find(word[index]);
    if (it != values.end())
      return it->second->add_word(word, index + 1);
    temp_value* temp = new temp_value();
    values[word[index]] = temp;
    return temp->add_word(word, index + 1);
  }

  bool find_word(const string& word, int index) {
    if (index == word.size())
      return values.find('@') != values.end();
    if (word[index] == '.') {
      bool found = false;
      for (const auto it : values)
        if (it.first != '@')
          found |= it.second->find_word(word, index + 1);
      return found;
    } else {
      auto it = values.find(word[index]);
      if (it == values.end())
        return false;
      return it->second->find_word(word, index + 1);
    }
  }
};

class WordDictionary {
 public:
  temp_value* temp = nullptr;
  WordDictionary() { temp = new temp_value(); }

  void addWord(string word) {
    // cout << "adding word : " << word << endl;
    temp->add_word(word, 0);
    // cout << "insertion complete" << endl;
    return;
  }

  bool search(string word) {
    // cout << "searching for word : " << word << endl;
    bool result = temp->find_word(word, 0);
    // cout << "result : " << boolalpha << result << endl;
    return result;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
