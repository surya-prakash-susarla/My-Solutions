#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long int llint;

llint n;
vector<llint> answer;
vector<llint> a;
vector<llint> b;
vector<llint> c;

void __print__(const vector<llint>&);

bool __rec__(vector<llint>& answer, int index) {
  if (index == n) {
    return answer[index - 1] != answer[0];
  }

  auto set_and_recurse = [&index, &answer](const llint value) {
    answer[index] = value;
    if (__rec__(answer, index + 1)) {
      return true;
    } else {
      return false;
    }
  };

  bool result = false;
  if (a[index] != answer[index - 1]) {
    result = set_and_recurse(a[index]);
    if (result)
      return true;
  }
  if (b[index] != answer[index - 1]) {
    result = set_and_recurse(b[index]);
    if (result)
      return true;
  }
  if (c[index] != answer[index - 1]) {
    result = set_and_recurse(c[index]);
    if (result)
      return true;
  }

  return false;
}

void __calc__(vector<llint>& answer) {
  cin >> n;

  a.resize(n, 0);
  b.resize(n, 0);
  c.resize(n, 0);

  auto take_input = [](vector<llint>& input) {
    for (llint i = 0; i < n; i++)
      cin >> input[i];
  };

  take_input(a);
  take_input(b);
  take_input(c);

  answer.resize(n, 0);

  answer[0] = a[0];
  if (__rec__(answer, 0))
    return;
  answer[0] = b[0];
  if (__rec__(answer, 0))
    return;
  answer[0] = c[0];
  if (__rec__(answer, 0))
    return;

  return;
}

void __print__(const vector<llint>& answer) {
  for (const llint i : answer)
    cout << i << " ";
  return;
}

int main() {
  llint t;
  cin >> t;
  for (llint i = 0; i < t; i++) {
    __calc__(answer);
    __print__(answer);
    if (i < t - 1)
      cout << endl;
  }
  return 0;
}