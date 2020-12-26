#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long int long_int;

long_int __calc__() {
  long_int n;
  long_int d;
  cin >> n >> d;
  vector<long_int> values(n);
  for_each(values.begin(), values.end(),
           [](long_int& current_value) { cin >> current_value; });
  for_each(values.rbegin(), values.rend(), [&d](const long_int& current_value) {
    d = (d / current_value) * current_value;
  });
  return d;
}

int main() {
  long_int t;
  cin >> t;
  for (long_int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": " << __calc__();
    if (i < t)
      cout << endl;
  }
  return 0;
}