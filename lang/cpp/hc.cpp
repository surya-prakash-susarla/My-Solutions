#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int p = 0, ne = 0, z = 0;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    if (temp < 0)
      ne += 1;
    else if (temp > 0)
      p += 1;
    else if (temp == 0)
      z += 1;
  }
  cout << doube(p / n) << "\n"
       << double(ne / n) << "\n"
       << double(z / n) << endl;
  return 0;
}
