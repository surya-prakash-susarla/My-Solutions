#include <iostream>
using namespace std;

int main() {
  int t, comm;
  cout << "Enter the number of test cases" << endl;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int m, n;
    cout << "Enter the sizes of the arrays " << endl;
    cin >> m >> n;
    int *a = new int[m];
    int *b = new int[n];
    comm = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (a[i] == b[j])
          comm += 1;
  }
  cout << "Value is " << comm << endl;
  return 0;
}
