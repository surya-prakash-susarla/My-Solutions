#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int llint;

// declarations
llint n;
vector<llint> a;

llint max(llint a, llint b) {
  if (a > b)
    return a;
  return b;
}

llint lis(llint ele, llint sum) {
  // cout<<"current value of element is "<<ele<<endl;
  // cout<<"the current length of sequence is "<<sum<<endl;
  // cout<<"ELEMENT IS _____________________" << a[ele]<<endl;
  // cout<<"next ele is ________" << a[ele+1]<<endl;
  if (ele >= n - 1)
    return sum;
  if (a[ele] > a[ele + 1])
    // return sum;
    return lis(ele + 2, sum + 1);
  return max(lis(ele + 1, sum + 1), lis(ele + 2, sum + 1));
}

int main() {
  // cout<<"enter the size of the list"<<endl;
  cin >> n;
  // cout<<"enter the elements of the list"<<endl;
  for (llint i = 0; i < n; i++) {
    llint temp;
    cin >> temp;
    a.push_back(temp);
  }
  // cout<<"the longest increasing sub sequence "<<endl;
  // cout<<"____________________________________________________________"<<endl;
  cout << lis(0, 0) << endl;
  // cout<<"program complete"<<endl;
  return 0;
}
