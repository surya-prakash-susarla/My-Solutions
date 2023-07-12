#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int llint;
int main() {
  llint n, k;
  // cout<<"enter n and k"<<endl;
  cin >> n >> k;
  llint backup = k;
  vector<llint> a;
  // cout<<"enter the prices"<<endl;
  for (llint i = 0; i < n; i++) {
    llint temp;
    cin >> temp;
    a.push_back(temp);
  }
  llint total = 0;
  llint mul = 0;
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  for (llint i = 0; i < a.size(); i++) {
    total += (mul + 1) * a[i];
    k -= 1;
    if (k == 0) {
      k = backup;
      mul++;
    }
  }
  cout << total << endl;
  return 0;
}
