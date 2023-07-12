#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int closest(vector<int> const &a, int value) {
  // const auto it = lower_bound(a.begin(),a.end(),value);
  const auto it = upper_bound(a.begin(), a.end(), value);
  if (it == a.end())
    return -1;
  return *it;
}

int main() {
  int n;
  cout << "enter the number of integers" << endl;
  cin >> n;
  vector<int> a;
  cout << "enter the numbers" << endl;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    a.push_back(temp);
  }
  cout << "enter the value to find the closest" << endl;
  int value;
  cin >> value;
  cout << closest(a, value) << endl;
  return 0;
}
