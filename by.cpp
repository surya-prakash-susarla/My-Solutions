#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
map<int, long long> f;

long long max(int a) {
  if (a == 0)
    return 0;
  if (f[a] != 0)
    return f[a];
  long long total = max(a / 2) + max(a / 3) + max(a / 4);
  if (total > a)
    f[a] = total;
  else
    f[a] = a;
  return f[a];
}
int main(int argc, char const *argv[]) {
  int n;
  while ((scanf("%d", &n)) == 1)
    cout << max(n) << endl;
  return 0;
}
