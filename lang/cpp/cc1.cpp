#include <iostream>
#include <vector>
using namespace std;
#define pb push_back
int main() {
  vector<int> a;
  int i;
  for (i = 3; i <= 8; i++)
    a.pb(i);
  for (i = 15; i <= 31; i++)
    a.pb(i);
  for (i = 62; i <= 125; i++)
    a.pb(i);
  for (i = 250; i <= 500; i++)
    a.pb(i);
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cout << a[i] << " ";
    cout << endl;
  }
  return 0;
}
