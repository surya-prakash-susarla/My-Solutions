#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {

  typedef pair<string, int> a;
  vector<pair<a, int>> f;
  cout << "enter the number of values" << endl;
  int n;
  cin >> n;
  f.resize(n);
  cout << "enter the values to be filled" << endl;
  for (int i = 0; i < n; i++) {
    string s;
    int a, b;
    cin >> s >> a >> b;
    f[i].first.first = s;
    f[i].first.second = a;
    f[i].second = b;
  }
  cout << "the entered values are " << endl;
  for (int i = 0; i < n; i++) {
    cout << f[i].first.first << " " << f[i].first.second << " " << f[i].second
         << endl;
  }
  cout << "\n\nenter a pair to be searched" << endl;

  return 0;
}
