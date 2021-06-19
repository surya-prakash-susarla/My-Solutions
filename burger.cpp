#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int llint;
int main() {
  llint size;
  // cout<<"enter the size"<<endl;
  cin >> size;
  vector<pair<llint, llint>> a;
  // cout<<"enter the details"<<endl;
  for (llint i = 0; i < size; i++) {
    llint temp1, temp2;
    cin >> temp1 >> temp2;
    temp2 += temp1;
    a.push_back(make_pair(i + 1, temp2));
  }
  sort(a.begin(), a.end(),
       [](const pair<llint, llint> left, const pair<llint, llint> right) {
         return left.second < right.second;
       });
  vector<pair<llint, llint>>::iterator it;
  for (it = a.begin(); it != a.end(); it++) {
    cout << it->first << " ";
  }
  return 0;
}
