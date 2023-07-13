#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string removeStars(string s) {
    int mark_char = '@';

    int del = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == '*')
        del++;
      else if (isalpha(s[i]) and del > 0) {
        s[i] = mark_char;
        del--;
      }
    }

    string answer;
    for (char c : s)
      if (isalpha(c))
        answer += c;

    return answer;
  }
};

int main() {
  return 0;
}
