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
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

typedef long long int llint;
typedef long long unsigned int ullint;

using namespace std;

class Solution {
 public:
  string reverseVowels(string s) {
    constexpr char dead_char = '%';

    set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    stack<char> temp;
    for (char& c : s) {
      if (vowels.find(c) != vowels.end() or
          vowels.find(tolower(c)) != vowels.end()) {
        temp.push(c);
        c = dead_char;
      }
    }

    string answer;
    for (char c : s) {
      if (c != dead_char)
        answer += c;
      else {
        answer += temp.top();
        temp.pop();
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
