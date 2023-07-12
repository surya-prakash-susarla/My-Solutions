#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    vector<int> a, b;
    int k;
    for (int i = 0; i < n; i++) {
      cin >> k;
      a.push_back(k);
    }
    for (int i = 0; i < n; i++) {
      cin >> k;
      b.push_back(k);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long int sum = 0;
    vector<int>::iterator f, g;
    for (f = a.begin(), g = b.begin(); f != a.end() && g != a.end(); f++, g++)
      sum = sum + ((*f) * (*g));
    cout << sum << endl;
  }
  return 0;
}
