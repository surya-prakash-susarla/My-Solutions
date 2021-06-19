#include <iostream>
#include <vector>
using namespace std;
typedef long long int llint;
#define pb push_back

int main() {
  llint t;
  cin >> t;
  while (t-- > 0) {
    llint p, q, r;
    cin >> p >> q >> r;
    vector<llint> a, b, c;
    a.resize(p);
    b.resize(q);
    c.resize(r);
    for (llint i = 0; i < p; i++)
      cin >> a[i];
    for (llint i = 0; i < q; i++)
      cin >> b[i];
    for (llint i = 0; i < r; i++)
      cin >> c[i];
    vector<llint> bval;
    bval.resize(q);
    for (llint i = 0; i < q; i++) {
      for (llint j = 0; j < r; j++) {
        if (c[j] <= b[i])
          bval[i] += (b[i] + c[j]);
      }
    }
    llint total = 0;
    for (llint i = 0; i < p; i++) {
      for (llint j = 0; j < q; j++) {
        if (a[i] <= b[j])
          total += (a[i] + b[j]) * bval[j];
      }
    }
    llint moduler = 1000000007;
    cout << total % moduler << endl;
  }
  return 0;
}
