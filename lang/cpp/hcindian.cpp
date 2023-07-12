#include <iostream>
#include <vector>
using namespace std;
typedef long long int llint;
llint size, g;
vector<llint> times;
bool numcal(llint n, llint a, llint b) {
  cout << "currenlty checking " << n << " " << a << " " << b << endl;
  if (n == size)
    return true;
  if (a > g or b > g or (a + times[n] > g and b + times[n] > g)) {
    cout << "returning false" << endl;
    return false;
  }
  if (a + times[n] > g)
    return numcal(n + 1, a, b + times[n]);
  if (b + times[n] > g)
    return numcal(n + 1, a + times[n], b);
  return (numcal(n + 1, a + times[n], b) or numcal(n + 1, a, b + times[n]));
}
int main() {
  llint t;
  cin >> t;
  while (t-- > 0) {
    cin >> size;
    cin >> g;
    times.resize(size);
    for (llint i = 0; i < size; i++)
      cin >> times[i];
    if (numcal(0, 0, 0))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    times.clear();
  }
  return 0;
}
