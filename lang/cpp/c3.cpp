#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    int k = n;
    long long int total = 0;
    while (n-- > 0) {
      long long int temp;
      cin >> temp;
      total += temp;
    }
    if (total % k == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
