#include <iostream>
#include <vector>
using namespace std;
typedef long long int llint;
#define pb push_back

void value(llint a, llint b, llint c, llint &value) {
  if (a > b or c > b)
    return;
  value += (a + b) * (b + c);
}

int main() {
  llint t;
  cin >> t;
  while (t-- > 0) {
    llint p, q, r;
    cin >> p >> q >> r;
    vector<llint> a, b, c;
    for (llint i = 0; i < p; i++) {
      llint temp;
      cin >> temp;
      a.push_back(temp);
    }
    for (llint i = 0; i < q; i++) {
      llint temp;
      cin >> temp;
      b.push_back(temp);
    }
    for (llint i = 0; i < r; i++) {
      llint temp;
      cin >> temp;
      c.push_back(temp);
    }
    llint total = 0;
    for (llint i = 0; i < p; i++)
      for (llint j = 0; j < q; j++)
        for (llint k = 0; k < r; k++)
          value(a[i], b[j], c[k], total);
    cout << total;
    cout << endl;
  }
  return 0;
}
