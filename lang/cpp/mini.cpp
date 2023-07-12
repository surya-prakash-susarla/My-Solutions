#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int llint;
int main() {
  llint n, k;
  // cout<<"enter the values of n and k"<<endl;
  cin >> n >> k;
  vector<llint> a;
  for (llint i = 0; i < n; i++) {
    llint temp;
    cin >> temp;
    a.push_back(temp);
  }
  sort(a.begin(), a.end());
  llint lowest = -1;
  llint te = k - 1;
  // cout<<"starting search"<<endl;
  for (llint i = 0; i <= a.size() - k; i++)
    if (lowest == -1 or a[i + te] - a[i] < lowest)
      lowest = a[i + te] - a[i];
  // cout<<"the answer is ";
  cout << lowest << endl;
  return 0;
}
