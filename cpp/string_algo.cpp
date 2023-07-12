#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cout << "enter any string" << endl;
  cin >> s;
  cout << "enter the character to be searched" << endl;
  char c;
  cin >> c;
  cout << find(s.begin(), s.end(), c) << endl;
  return 0;
}
