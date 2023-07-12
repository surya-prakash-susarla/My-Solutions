#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int m, total;
  cin >> m;
  while (m != 0) {
    total = 0;
    for (int i = 1; i <= m; i++) {
      total = total + ((m - (i - 1)) * (m - (i - 1)));
    }
    cout << total << endl;
    cin >> m;
  }
  return 0;
}
