#include <iostream>
using namespace std;
int main() {
  int a1, a2, a3;
  cin >> a1 >> a2 >> a3;
  while (a1 != 0 || a2 != 0 || a3 != 0) {
    if (2 * a2 == (a1 + a3)) {
      cout << "AP ";
      cout << a3 + (a3 - a2) << endl;
    } else if ((a2 * a2) == (a1 * a3)) {
      cout << "GP ";

      //  cout<<a3/a2<<endl;

      cout << a3 * (a3 / a2) << endl;
    }
    cin >> a1 >> a2 >> a3;
  }
  return 0;
}
