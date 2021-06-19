#include <iostream>
#include <map>
#include <vector>
using namespace std;

int num(int a) {
  vector<int> f;
  f.push_back(1);
  f.push_back(a);
  for (int i = 2; i <= a / 2; i++) {
    if (a % i == 0)
      f.push_back(i);
  }
  int count = 0;
  if (f.size() % 2 == 0)
    return f.size() / 2;
  else {
    return 1 + ((f.size() - 1) / 2);
  }
}

int main() {
  map<int, int> ma;
  int n;
  cin >> n;
  int total = 0;
  for (int i = 1; i <= n; i++) {
    if (ma[i] != 0)
      total = total + ma[i];
    else {
      ma[i] = num(i);
      total = total + ma[i];
    }
  }
  cout << total << endl;
  return 0;
}
