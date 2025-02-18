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
  typedef vector<string> vstring;

  string solve(const string& a, const string& b, const char token) {
    switch (token) {
      case '+':
        return to_string(stoi(a) + stoi(b));
      case '-':
        return to_string(stoi(a) - stoi(b));
      case '*':
        return to_string(stoi(a) * stoi(b));
      case '/':
        return to_string(stoi(a) / stoi(b));
    }
    cout << "ERROR: Unknown token : " << token << endl;
    return "";
  }

  vector<string> apply(const vstring& current, const set<char>& tokens) {
    vstring result;

    string prev = current[0];
    for (int i = 1; i < current.size(); i = i + 2) {
      // cout << "current symbol : " << current[i] << endl;
      // cout << "prev : " << prev << " , next : " << current[i+1] << endl;
      if (tokens.contains(current[i][0])) {
        string result = solve(prev, current[i + 1], current[i][0]);
        prev = result;
      } else {
        result.push_back(prev);
        result.push_back(current[i]);
        prev = current[i + 1];
      }
    }
    result.push_back(prev);

    return result;
  }

  int calculate(string s) {
    vector<string> tokens;
    string current;
    for (char c : s) {
      if (c == ' ') {
        if (not current.empty()) {
          tokens.emplace_back(current);
          current = "";
        }
      } else {
        if (c == '/' or c == '+' or c == '-' or c == '*') {
          if (not current.empty()) {
            tokens.emplace_back(current);
          }
          tokens.emplace_back(string(1, c));
          current = "";
        } else {
          current += c;
        }
      }
    }
    if (not current.empty())
      tokens.emplace_back(current);

    // cout << "tokens : " << endl;
    // for ( string i : tokens )   cout << i << " ";
    // cout << endl;

    tokens = apply(tokens, {'/', '*'});
    tokens = apply(tokens, {'+', '-'});

    // tokens = apply(tokens, '/');
    // tokens = apply(tokens, '*');
    // tokens = apply(tokens, '+');
    // tokens = apply(tokens, '-');

    if (tokens.size() > 1)
      cout << "ERROR: tokens size greater than 1" << endl;

    return stoi(tokens[0]);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
