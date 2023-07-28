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
  typedef vector<int> vint;
  typedef vector<vint> vvint;
  typedef vector<bool> vbool;
  typedef vector<vbool> vvbool;

  int n;
  int m;

  vvbool visited;

  typedef struct _x {
    int rs;
    int re;
    int cs;
    int ce;

    _x() = default;

    _x(int a, int b, int c, int d) : rs(a), re(b), cs(c), ce(d) {}
  } pos;

  enum type { ltr, rtb, rtl, btt };

  pos update(pos input, type dir) {
    switch (dir) {
      case type::ltr:
        return pos(input.rs + 1, input.re + 1, input.cs + 1, input.ce - 1);
      case type::rtb:
        return pos(input.rs + 1, input.re - 1, input.cs - 1, input.ce - 1);
      case type::rtl:
        return pos(input.rs - 1, input.re - 1, input.cs - 1, input.ce + 1);
      case type::btt:
        return pos(input.rs - 1, input.re + 1, input.cs + 1, input.ce - 1);
    }
  }

  vint print(const vvint& values, pos input, type dir) {
    vint answer;

    auto ins = [&](int i, int j) {
      if (not visited[i][j]) {
        visited[i][j] = true;
        answer.push_back(values[i][j]);
      }
    };

    switch (dir) {
      case type::ltr: {
        for (int i = input.cs; i <= input.ce; i++)
          ins(input.rs, i);
        break;
      }
      case type::rtb: {
        for (int i = input.rs; i <= input.re; i++)
          ins(i, input.cs);
        break;
      }
      case type::rtl: {
        for (int i = input.cs; i >= input.ce; i--)
          ins(input.rs, i);
        break;
      }
      case type::btt: {
        for (int i = input.rs; i >= input.re; i--)
          ins(i, input.cs);
        break;
      }
    }

    return answer;
  }

  vector<int> spiralOrder(vector<vector<int>>& input) {
    n = input.size();
    m = input[0].size();

    if (n == 1) {
      return input[0];
    }

    if (m == 1) {
      vint answer;
      for (int i = 0; i < n; i++)
        answer.push_back(input[i][0]);
      return answer;
    }

    visited = vvbool(n, vbool(m, false));

    pos ltr(0, 0, 0, m - 2);
    pos rtb(0, n - 2, m - 1, m - 1);
    pos rtl(n - 1, n - 1, m - 1, 1);
    pos btt(n - 1, 1, 0, 0);

    bool valid = true;
    vint answer;

    while (valid) {
      valid = false;
      vint current;

      current = print(input, ltr, type::ltr);
      ltr = update(ltr, type::ltr);
      answer.insert(answer.end(), current.begin(), current.end());
      valid |= (!current.empty());

      current = print(input, rtb, type::rtb);
      rtb = update(rtb, type::rtb);
      answer.insert(answer.end(), current.begin(), current.end());
      valid |= (!current.empty());

      current = print(input, rtl, type::rtl);
      rtl = update(rtl, type::rtl);
      answer.insert(answer.end(), current.begin(), current.end());
      valid |= (!current.empty());

      current = print(input, btt, type::btt);
      btt = update(btt, type::btt);
      answer.insert(answer.end(), current.begin(), current.end());
      valid |= (!current.empty());
    }

    if (n == m and n % 2 and not visited[n / 2][m / 2]) {
      answer.push_back(input[n / 2][m / 2]);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
