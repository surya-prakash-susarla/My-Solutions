#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  cout << "enter 5 pairs" << endl;
  vector<pair<int, int>> a;
  for (int i = 0; i < 5; i++) {
    int temp1, temp2;
    cin >> temp1 >> temp2;
    a.push_back(make_pair(temp1, temp2));
  }
  cout << "the entered values are" << endl;
  for (int i = 0; i < 5; i++) {
    cout << a[i].first << " " << a[i].second << endl;
  }
  cout << "sorting the pairs" << endl;
  sort(a.begin(), a.end(),
       [](const pair<int, int> left, const pair<int, int> right) {
         return left.second < right.second;
       });
  for (int i = 0; i < 5; i++)
    cout << a[i].first << " " << a[i].second << endl;
  return 0;
}
