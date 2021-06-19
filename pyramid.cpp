#include <iomanip>
#include <iostream>
using namespace std;
typedef long long int llint;
llint first = 6, second = 28, diff = 16;
bool unf = true, uns = true;
llint num(void) {
  if (unf) {
    unf = false;
    return first;
  }
  if (uns) {
    uns = false;
    return second;
  } else {
    llint temp = second;
    second = second + ((second - first) + diff);
    first = temp;
    return second;
  }
  return 0;
}

int main() {
  llint n;
  cin >> n;
  llint back = n;
  for (llint i = 0; i < back; i++) {
    for (llint j = 0; j < n - 1; j++)
      cout << " ";
    n -= 1;
    for (llint j = 0; j < i + 1; j++) {
      cout << setfill('0') << setw(5) << num();
      if (j < i)
        cout << " ";
    }
    cout << endl;
  }
  return 0;
}
