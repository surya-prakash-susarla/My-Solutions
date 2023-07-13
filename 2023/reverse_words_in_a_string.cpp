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
  string reverseWords(string input) {
    vector<string> words;
    string current;

    for (char i : input) {
      if (i == ' ') {
        if (not current.empty())
          words.push_back(current);
        current = "";
      } else {
        current = current + i;
      }
    }

    if (not current.empty())
      words.push_back(current);

    reverse(words.begin(), words.end());

    string answer;
    for (int i = 0; i < words.size(); i++) {
      answer += words[i];

      if (i < words.size() - 1)
        answer += ' ';
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
