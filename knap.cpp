#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int llint;
llint **vals;

llint inline highest(llint a, llint b) {
  if (a > b)
    return a;
  return b;
}

int highs(vector<llint> a, llint n, llint sum, llint limit) {
  if (n == 0)
    return 0;
  if (sum > limit)
    return 0;
  if (vals[n][sum] != -1)
    return vals[n][sum];
  llint temper = -1;
  if (n > 1)
    temper = highs(a, n - 1, sum, limit);
  if (sum + a[n - 1] > limit)
    // UNCOMMENT FOR MOST CORRECT SOLUTION
    // return sum;
    return highest(temper, sum);
  //	if(sum+a[n-1]==limit)
  //		return sum+a[n-1];
  llint temp = highs(a, n, sum + a[n - 1], limit);
  //	llint temper=-1;
  //	if(n>1)
  //		temper = highs(a,n-1,sum,limit);
  temp = highest(temp, temper);
  vals[n][sum] = temp;
  return temp;
}

int main() {
  llint t;
  // cout<<"enter the number of test cases"<<endl;
  cin >> t;
  while (t-- > 0) {
    llint n, sum;
    //	cout<<"enter the number of values and the sum required"<<endl;
    cin >> n >> sum;
    vector<llint> a;
    //	cout<<"enter the values"<<endl;
    for (llint i = 0; i < n; i++) {
      llint temp;
      cin >> temp;
      a.push_back(temp);
    }
    vals = new llint *[2001];
    for (llint i = 0; i < 2001; i++) {
      vals[i] = new llint[2001];
      for (llint j = 0; j < 2001; j++)
        vals[i][j] = -1;
    }
    cout << highs(a, n, 0, sum) << endl;
  }
  return 0;
}
