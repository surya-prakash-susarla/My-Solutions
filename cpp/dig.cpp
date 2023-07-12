#include <cmath>
#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int a;
    long long b;
    cin >> a >> b;
    if (b == 0) {
      cout << "1" << endl;
      continue;
    }
    int base = a % 10;
    long long exp = b % 4 == 0 ? 4 : b % 4;
    cout << (long long int)pow(base, exp) % (long long int)10 << endl;
  }
  return 0;
}
