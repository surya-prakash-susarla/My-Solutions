#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int llint;
int main() {
  llint n;
  // cout<<"enter the size"<<endl;
  cin >> n;
  vector<llint> a;
  // cout<<"enter the elements"<<endl;
  for (llint i = 0; i < n; i++) {
    llint temp;
    cin >> temp;
    a.push_back(temp);
  }
  // cout<<"the longest increasing sub sequence is "<<endl;
  vector<llint> lcs;
  lcs.push_back(a[0]);
  for (llint i = 1; i < a.size(); i++) {
    if (a[i] > lcs[lcs.size() - 1])
      lcs.push_back(a[i]);
    else {
      const auto it = upper_bound(lcs.begin(), lcs.end(), a[i]);
      *it = a[i];
    }
    sort(lcs.begin(), lcs.end());
  }
  // cout<<"the main search function is complete"<<endl;
  // cout<<"the length of the sorted vector is ";
  cout << lcs.size() << endl;
  // cout<<"the elements of the lcs vector are "<<endl;
  // vector<llint>::iterator it;
  // for(it  = lcs.begin();it!=lcs.end();it++)
  //	cout<<*it<<" ";
  // cout<<endl;
  return 0;
}
