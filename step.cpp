#include <iostream>
using namespace std;
int d1 = 1, d2 = 3;
int x1 = 0, x2 = 2;
void same(int x) {
  int t = x1;
  int d = d1;
  for (int i = 0; i < x; i++) {
    t = t + d;
    d == d1 ? d = d2 : d = d1;
  }
  cout << t << endl;
}
void diff(int x) {
  int t = x2;
  int d = d1;
  for (int i = 2; i < x; i++) {
    t = t + d;
    d == d1 ? d = d2 : d = d1;
  }
  cout << t << endl;
}
int main() {
  int n;
  cin >> n;
  while (n-- > 0) {
    int x, y;
    cin >> x >> y;
    if (x == y)
      same(x);
    else if (x - y == 2)
      diff(x);
    else
      cout << "No Number" << endl;
  }
  return 0;
}
