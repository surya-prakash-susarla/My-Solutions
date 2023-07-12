#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int u = 0; u < t; u++) {
    int n;
    cin >> n;
    int *x = new int[n];
    int *y = new int[n];
    for (int i = 0; i < n; i++)
      cin >> x[i];
    for (int i = 0; i < n; i++)
      cin >> y[i];
    int min1 = 0, min2 = 0;
    min1 = x[0], min2 = y[0];
    for (int i = 1; i < n; i++)
      if (i % 2 == 0) {
        min1 += x[i];
        min2 += y[i];
      } else {
        min1 += y[i];
        min1 += x[i];
      }
    System.out.println(min1 < min2 ? min1 : min2);
  }
  return 0;
}
