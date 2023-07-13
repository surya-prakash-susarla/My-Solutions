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

  bool find_prefix(const string& word, int index) {
    if (index == word.size())
      return true;
    auto it = values.find(word[index]);
    if (it == values.end())
      return false;
    return it->second->find_prefix(word, index + 1);
  }

  bool find_word(const string& word, int index) {
    if (index == word.size())
      return values.find('@') != values.end();
    auto it = values.find(word[index]);
    if (it == values.end())
      return false;
    return it->second->find_word(word, index + 1);
  }

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
};

class Trie {
 public:
  temp_value* temp = nullptr;
  Trie() { temp = new temp_value(); }

  void insert(string word) {
    // cout << "inserting word : " << word << endl;
    temp->add_word(word, 0);
    // cout << "word inserted" << endl;
  }

  bool search(string word) {
    //    cout << "searching for word : " << word << endl;
    bool result = temp->find_word(word, 0);
    //    cout << "result : " << std::boolalpha << result << endl;
    return result;
  }

  bool startsWith(string prefix) {
    // cout << "searching for prefix : " << prefix << endl;
    bool result = temp->find_prefix(prefix, 0);
    // cout << "result : " << boolalpha << result << endl;
    return result;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
