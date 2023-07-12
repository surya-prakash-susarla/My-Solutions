#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int k = 0; k < t; k++) {
    int n;
    cin >> n;
    int *a = new int[n];
    int *f = new int[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> f[i];
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < n - 1; i++) {
        if (f[i] > f[i + 1]) {
          int temp = f[i];
          f[i] = f[i + 1];
          f[i + 1] = temp;
          temp = a[i];
          a[i] = a[i + 1];
          a[i + 1] = temp;
        }
      }
    }
    int count = 1;
    int val = f[0];
    for (int i = 1; i < n; i++) {
      if (a[i] >= val) {
        count += 1;
        val = f[i];
      }
    }
    cout << count;
  }
  return 0;
}
