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
  vector<string> tokenize(const string input) {
    vector<string> answer;
    string current;
    for (int i = 0; i < input.size(); i++) {
      if ('0' <= input[i] and input[i] <= '9') {
        current += input[i];
      } else if (input[i] == ' ') {
        if (not current.empty()) {
          answer.emplace_back(current);
          current.clear();
        }
        continue;
      } else {
        if (not current.empty()) {
          answer.emplace_back(current);
          current.clear();
        }
        answer.push_back(string(1, input[i]));
      }
    }
    if (not current.empty()) {
      answer.emplace_back(current);
    }

    // cout << "input string ; " << input << endl;
    // cout << "tokens size : " << answer.size() << endl;
    // for ( string i : answer )   cout << i << ",";
    // cout << endl;

    return answer;
  }

  int find_end(const vector<string>& input, int si) {
    int count = 1;
    for (int i = si + 1; i < input.size(); i++) {
      if (input[i] == "(") {
        count++;
      } else if (input[i] == ")") {
        count--;
        if (count == 0)
          return i;
      }
    }
    return input.size() - 1;
  }

  int __calc__(int si, int ei, const vector<string>& input) {
    // cout << "limits, si : " << si << " , ei : " << ei << endl;
    int current = 0;
    bool is_neg = false;
    for (int i = si; i <= ei; i++) {
      // cout << "current : " << current << " , is neg : " << is_neg << " ,
      // value : " << input[i] << endl;
      if (input[i] == "-") {
        is_neg = true;
      } else if (input[i] == "+") {
        is_neg = false;
      } else if (input[i] == "(") {
        int end_index = find_end(input, i);
        int value = __calc__(i + 1, end_index - 1, input);
        if (is_neg) {
          current -= value;
        } else {
          current += value;
        }
        is_neg = not is_neg;
        i = end_index;
      } else {
        if (is_neg) {
          current -= stoi(input[i]);
        } else {
          current += stoi(input[i]);
        }
        is_neg = not is_neg;
      }
    }
    // cout << "final current value : " << current << endl;
    return current;
  }

  int calculate(string s) {
    vector<string> tokens = tokenize(s);

    return __calc__(0, tokens.size() - 1, tokens);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
