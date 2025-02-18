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
  string reverseWords(string s) {
    string current;
    stack<string> words;
    for (char c : s) {
      if (c == ' ') {
        if (not current.empty())
          words.push(current);
        current = "";
      } else {
        current += c;
      }
    }
    if (not current.empty())
      words.push(current);

    string answer;
    for (; not words.empty(); words.pop()) {
      if (not answer.empty())
        answer += " ";
      answer += words.top();
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
