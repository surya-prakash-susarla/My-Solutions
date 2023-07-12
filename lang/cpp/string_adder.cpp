#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

bool searcher(string s, char c) {
  for (int i = 0; i < s.size(); i++)
    if (s[i] == c)
      return true;
  return false;
}

int main() {
  int t;
  cout << "enter the number of test cases" << endl;
  cin >> t;
  while (t-- > 0) {
    string a, b;
    cout << "enter the strings " << endl;
    cin >> a;
    cin >> b;
    cout << "the entered strings are " << endl;
    cout << a << "\n" << b << endl;
    string removed = "";
    for (int i = 0; i < b.size(); i++) {
      int t = a.size();
      a.erase(remove(a.begin(), a.end(), b[i]), a.end());
      if (a.size() < t or searcher(removed, b[i])) {
        removed += b[i];
        b.erase(remove(b.begin(), b.end(), b[i]), b.end());
      }
    }
    if (a.size() + b.size() > 0)
      cout << a + b << endl;
    else
      cout << "-1" << endl;
  }
  return 0;
}
