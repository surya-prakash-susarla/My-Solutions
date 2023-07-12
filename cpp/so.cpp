#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<string> a;
  for (int i = 0; i < 5; i++) {
    string s;
    cin >> s;
    a.push_back(s);
  }
  cout << endl << endl;
  vector<string>::iterator f;
  for (f = a.begin(); f != a.end(); f++)
    cout << *f << endl;
  cout << endl;
  sort(a.begin(), a.end());
  cout << endl;
  for (f = a.begin(); f != a.end(); f++)
    cout << *f << endl;
  return 0;
}
