#include <cstring>
#include <iostream>
using namespace std;
int max(int a, int b) { return a > b ? a : b; }
int lcs(string x, string y, int m, int n) {
  int l[m + 1][n + 1];
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        l[i][j] = 0;
      else if (x[i - 1] == y[j - 1])
        l[i][j] = 1 + l[i - 1][j - 1];
      else
        l[i][j] = max(l[i - 1][j], l[i][j - 1]);
    }
  }
  cout << "\n\n\n";
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      cout << l[i][j] << "\t";
    }
    cout << endl;
  }
  return l[m][n];
}
int main() {
  string a, b;
  cout << "Enter the two strings" << endl;
  cin >> a >> b;
  int m, n;
  m = a.length();
  n = a.length();
  cout << "The length of the largest substring is " << lcs(a, b, m, n) << endl;
  return 0;
}
