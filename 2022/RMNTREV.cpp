#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

typedef long long int llint;
typedef long double ldouble;

using namespace std;

string __calc__() {
  llint n, k;
  string values;
  cin >> n >> k;
  cin >> values;

  string answer = values;

  bool is_fw = true;
  int fwi = 0, bwi = k - 1;
  int ci = k - 1;

  while (fwi <= bwi) {
    if (is_fw) {
      answer[ci--] = values[fwi++];
    } else {
      answer[ci--] = values[bwi--];
    }
    is_fw = not is_fw;
  }

  return answer;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  llint t;
  cin >> t;
  for (llint i = 0; i < t; i++) {
    cout << __calc__();
    if (i < t - 1) {
      cout << endl;
    }
  }

  return 0;
}
