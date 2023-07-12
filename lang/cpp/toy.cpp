#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> a;
  for (long long int i = 0; i < n; i++) {
    long long int temp;
    cin >> temp;
    a.push_back(temp);
  }
  sort(a.begin(), a.end());
  long long int num = 0;
  for (int i = 0; i < a.size(); i++) {
    //	cout<<a[i]<<endl;
    if (a[i] < k) {
      k -= a[i];
      num += 1;
    } else
      break;
  }
  cout << num << endl;
  return 0;
}
