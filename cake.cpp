#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  vector<long long int> a;
  for (int i = 0; i < n; i++) {
    long long int temp;
    cin >> temp;
    a.push_back(temp);
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  long long int toc = 0, cok = 0;
  for (int i = 0; i < n; i++)
    toc += (a[i] * pow(2, cok++));
  // cout<<"the total cost is ";
  cout << toc << endl;
  return 0;
}
