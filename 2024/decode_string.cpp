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
  inline bool isnum(char c) { return c >= '0' and c <= '9'; }

  int find_ending_brace(int si, const string& s) {
    int count = 1;
    for (int i = si + 1; i < s.size(); i++) {
      if (s[i] == '[')
        count++;
      else if (s[i] == ']')
        count--;
      if (count == 0)
        return i;
    }
    return -1;
  }

  pair<int, pair<int, int>> getsub(int si, const string& s) {
    int i = si;
    for (; isnum(s[si]); si++)
      ;
    si--;
    int num = stoi(s.substr(i, si - i + 1));
    int ending_frame = find_ending_brace(si + 1, s);
    return make_pair(num, make_pair(si + 2, ending_frame - 1));
  }

  string rep(int n, const string& s) {
    string answer;
    for (int i = 0; i < n; i++)
      answer += s;
    return answer;
  }

  string proc(int si, int ei, string s) {
    string answer;
    for (int i = si; i <= ei; i++) {
      if (isnum(s[i])) {
        pair<int, pair<int, int>> subs = getsub(i, s);
        string internal_string = proc(subs.second.first, subs.second.second, s);
        answer += rep(subs.first, internal_string);
        i = subs.second.second + 1;
      } else {
        answer += s[i];
      }
    }
    return answer;
  }

  string decodeString(string s) { return proc(0, s.size() - 1, s); }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
