#include <bits/stdc++.h>
using namespace std;

typedef long long int llint;

#define mpb map<pair<llint, llint>, bool>

bool r_play(llint, llint, mpb&, mpb&);

bool a_play(llint n, llint m, mpb& a_memo, mpb& b_memo) {
  if (n == m or n == 1 or m == 1)
    return true;
  if (n == 0 or m == 0)
    return false;
  if (a_memo.find(pair<llint, llint>(n, m)) != a_memo.end())
    return a_memo[pair<llint, llint>(n, m)];
  bool result = false;
  if (n > m) {
    for (llint i = n / m; i > 0; i--)
      if (not r_play(n - m * i, m, a_memo, b_memo)) {
        result = true;
        break;
      }
  } else {
    for (llint i = m / n; i > 0; i--)
      if (not r_play(n, m - n * i, a_memo, b_memo)) {
        result = true;
        break;
      }
  }
  a_memo.insert(
      pair<pair<llint, llint>, bool>(pair<llint, llint>(n, m), result));
  return result;
}

bool r_play(llint n, llint m, mpb& a_memo, mpb& b_memo) {
  if (n == m or n == 1 or m == 1)
    return true;
  if (n == 0 or m == 0)
    return false;
  if (b_memo.find(pair<llint, llint>(n, m)) != b_memo.end())
    return b_memo[pair<llint, llint>(n, m)];
  bool result = false;
  if (n > m) {
    for (llint i = n / m; i > 0; i--)
      if (not a_play(n - m * i, m, a_memo, b_memo)) {
        result = true;
        break;
      }
  } else {
    for (llint i = m / n; i > 0; i--)
      if (not a_play(n, m - n * i, a_memo, b_memo)) {
        result = true;
        break;
      }
  }
  b_memo.insert(
      pair<pair<llint, llint>, bool>(pair<llint, llint>(n, m), result));
  return result;
}

string calc(llint n, llint m) {
  mpb a_memo, b_memo;
  if (a_play(n, m, a_memo, b_memo))
    return string("Ari");
  else
    return string("Rich");
  return string();
}

int main() {
  llint t;
  cin >> t;
  while (t-- > 0) {
    llint n, m;
    cin >> n >> m;
    cout << calc(n, m);
    if (t + 1 > 1)
      cout << endl;
  }
  return 0;
}