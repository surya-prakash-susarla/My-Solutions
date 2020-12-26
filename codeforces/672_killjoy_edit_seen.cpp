#include <iostream>
#include <vector>

using namespace std;

typedef long long int llint;

llint __calc__() {
  llint n, x;
  cin >> n >> x;
  vector<llint> values(n);

  bool infected = false;
  bool all_infected = true;
  for (llint i = 0; i < n; i++) {
    cin >> values[i];
    if (values[i] == x)
      infected = true;
    else
      all_infected = false;
  }

  if (all_infected)
    return 0;
  else if (infected)
    return 1;

  llint net_diff = 0;
  for (const llint& i : values)
    net_diff += x - i;

  if (net_diff == 0)
    return 1;

  return 2;
}

int main() {
  llint t;
  cin >> t;
  for (llint i = 0; i < t; i++) {
    llint answer = __calc__();
    cout << answer;
    if (i < t - 1)
      cout << endl;
  }
  return 0;
}