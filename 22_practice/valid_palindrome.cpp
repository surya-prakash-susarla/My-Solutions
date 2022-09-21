#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isPalindrome(string input) {
    string value;
    for (char c : input) {
      if (isalpha(c)) {
        value += tolower(c);
      } else if (isdigit(c)) {
        value += c;
      }
    }

    string temp(value);
    reverse(temp.begin(), temp.end());

    return temp == value;
  }
};

int main() {
  return 0;
}
