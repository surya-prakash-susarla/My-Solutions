#include <iostream>

using namespace std;
typedef long long int llint;

int main() {
  llint t;
  cin >> t;
  while (t-- > 0) {
    llint n, m, x, y, init_x = 1, init_y = 1;
    cin >> n >> m >> x >> y;
    n -= 1;
    m -= 1;
    bool share_used = false;
    llint req_n = n % x;
    llint req_m = m % y;
    if ((req_m == 1 and req_n == 1) or (req_n == 0 and req_m == 0) or
        (x == 1 and req_m == 1 and n != 0) or
        (req_n == 1 and y == 1 and m != 0))
      cout << "Chefirnemo";
    else
      cout << "Pofik";
    if (t > 0)
      cout << endl;
  }
  return 0;
}