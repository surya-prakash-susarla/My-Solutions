#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int llint;

int main() {
  llint t;
  // cout<<"enter the number of test cases"<<endl;
  cin >> t;
  while (t-- > 0) {
    llint n, k;
    //	cout<<"enter the size and the sum"<<endl;
    cin >> n >> k;
    vector<llint> a, b;
    //	cout<<"enter the first set of elements"<<endl;
    for (llint i = 0; i < n; i++) {
      llint temp;
      cin >> temp;
      a.push_back(temp);
    }
    //	cout<<"enter the second set of elements"<<endl;
    for (llint i = 0; i < n; i++) {
      llint temp;
      cin >> temp;
      b.push_back(temp);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    bool failed = false;
    //	cout<<"checking for conditions in for loop"<<endl;
    for (llint i = 0; i < n; i++) {
      if (a[i] + b[i] < k) {
        //			cout<<"NO"<<endl;
        failed = true;
      }
    }
    if (not failed)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  // cout<<"out of the while loop"<<endl;
  return 0;
}
