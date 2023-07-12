#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int llint;
int main() {
  llint t;
  cin >> t;
  while (t-- > 0) {
    llint n;
    cin >> n;
    vector<llint> a;
    for (llint i = 0; i < n; i++) {
      llint temp;
      cin >> temp;
      a.push_back(temp);
    }
    llint profit = 0;
    llint i = a.size() - 1, max = a[i];
    while (i-- > 0) {
      // cout<<"the value is "<<a[i]<<endl;
      if (a[i] < max) {
        //	cout<<"profit increased "<<profit<<endl;
        profit += (max - a[i]);
      } else if (a[i] > max)
        max = a[i];
    }
    cout << profit << endl;
  }
  return 0;
}
