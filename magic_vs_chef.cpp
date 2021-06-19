#include <iostream>
using namespace std;

typedef long long int llint;

int main() {
  llint t;
  cin >> t;
  while (t-- > 0) {
    llint n, current, total;
    cin >> n >> current >> total;

    for (llint i = 0; i < total; i++) {
      llint a, b;
      cin >> a >> b;
      if (current == a)
        current = b;
      else if (current == b)
        current = a;
    }

    cout << current;

    if (t > 0)
      cout << endl;
  }
  return 0;
}