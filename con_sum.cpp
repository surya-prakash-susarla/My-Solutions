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
    // cout<<"enter the size of the values"<<endl;
    cin >> n;
    vector<llint> a;
    // cout<<"enter the values"<<endl;
    for (llint i = 0; i < n; i++) {
      llint temp;
      cin >> temp;
      a.push_back(temp);
    }
    vector<llint> values;
    values.resize(n);
    // cout<<"the start of finding highest values "<<endl;
    values[a.size() - 1] = a[a.size() - 1];
    // cout<<"the ending max value is "<<values[a.size()-1]<<endl;
    for (llint i = a.size() - 2; i >= 0; i--) {
      llint temp = a[i] + values[i + 1];
      if (a[i] > temp)
        values[i] = a[i];
      else
        values[i] = temp;
      //	cout<<"the final values are "<<values[i]<<endl;
    }
    // cout<<"the values of the highest sums are "<<endl;
    vector<llint>::iterator it;
    // for(it=values.begin();it!=values.end();it++)
    //	cout<<*it<<"\t";
    // cout<<endl;
    llint max = *max_element(values.begin(), values.end());
    // cout<<"the max value is ";
    cout << max << " ";
    // cout<<"\n\nstarting search of non contiguous values"<<endl;
    llint maxer = 0;
    for (it = a.begin(); it != a.end(); it++) {
      if (*it > 0)
        maxer += *it;
    }
    if (maxer == 0)
      cout << *max_element(a.begin(), a.end()) << endl;
    // cout<<"the non conitguous value is ";
    else
      cout << maxer << endl;
  }
  return 0;
}
