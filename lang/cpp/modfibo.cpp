#include <algorithm>
#include <iostream>
#include <vector>
#define squ(x) (x * x)
using namespace std;
typedef long long int llint;
int main() {
  llint t1, t2, n;
  cin >> t1 >> t2 >> n;
  vector<llint> fibo;
  fibo.push_back(t1);
  fibo.push_back(t2);
  for (llint i = 3; i <= n; i++)
    fibo[i] = fibo[i - 2] + squ(fibo[i - 1]);
  cout << fibo[n] << endl;
  return 0;
}
