#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int k;
  cin >> k;

  vector<long long int> imp;
  long long int total = 0;
  for (long long int i = 0; i < n; i++) {
    long long int l, o;
    cin >> l >> o;
    if (o == 0)
      total += l;
    else {
      imp.push_back(l);
      total += l;
    }
    //	cout<<"temp total is "<<total<<endl;
  }
  sort(imp.begin(), imp.end());
  // cout<<"the value of k is "<<k<<endl;
  // cout<<"the total important contests are "<<imp.size()<<endl;
  // cout<<"compelted sorting"<<endl;
  if (k > imp.size())
    k = imp.size();
  for (long long int i = 0; i < imp.size() - k; i++) {
    //	cout<<"index is "<<i<<endl;
    total -= 2 * imp[i];
  }
  // cout<<"total luck is ";
  cout << total << endl;
  return 0;
}
