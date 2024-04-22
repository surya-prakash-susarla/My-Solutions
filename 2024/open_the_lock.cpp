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
  typedef unordered_set<string> uset;

  inline char get_next(char a) { return a == '9' ? '0' : (char)((int)a + 1); }

  inline char get_prev(char a) { return a == '0' ? '9' : (char)((int)a - 1); }

  void gen(const string& input, uset& output) {
    for (int i = 0; i < 4; i++) {
      {
        string temp = input;
        temp[i] = get_next(input[i]);
        output.insert(temp);
      }
      {
        string temp = input;
        temp[i] = get_prev(input[i]);
        output.insert(temp);
      }
    }
  }

  int __calc__(const vector<string>& init_dead, const string& target) {
    uset values;
    values.insert("0000");
    int answer = 0;
    uset covered;
    uset dead(init_dead.begin(), init_dead.end());
    while (not values.empty()) {
      uset next;
      for (auto i : values) {
        if (i == target)
          return answer;
        if (dead.find(i) != dead.end())
          continue;
        if (covered.find(i) != covered.end())
          continue;
        covered.insert(i);
        gen(i, next);
      }
      answer++;
      swap(values, next);
    }
    return -1;
  }

  int openLock(vector<string>& deadends, string target) {
    return __calc__(deadends, target);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
