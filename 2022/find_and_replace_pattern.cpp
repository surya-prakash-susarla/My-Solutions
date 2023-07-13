#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    pattern = __gen_pattern__(pattern);
    vector<string> answer;
    for (const string& i : words) {
      if (__calc__(i, pattern))
        answer.push_back(i);
    }
    return answer;
  }

  bool __calc__(const string& input, const string& pattern) {
    map<char, char> temp;
    optional<char> temp2;
    for (int i = 0; i < pattern.size(); i++) {
      if (pattern[i] != __get_char__(input[i], temp, temp2))
        return false;
    }
    return true;
  }

  string __gen_pattern__(const string& value) {
    string answer = value;
    map<char, char> temp;
    optional<char> temp2;
    for (int i = 0; i < value.size(); i++)
      answer[i] = __get_char__(value[i], temp, temp2);
    return answer;
  }

  char __get_char__(char c,
                    map<char, char>& value_map,
                    optional<char>& current_char) {
    auto it = value_map.find(c);
    if (it != value_map.end())
      return it->second;
    char con_char =
        not current_char.has_value() ? 'a' : current_char.value() + 1;
    current_char = con_char;
    value_map[c] = con_char;
    return con_char;
  }
};
