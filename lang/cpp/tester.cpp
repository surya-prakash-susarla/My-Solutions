#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
  string main = "suryasuryasurya";
  string value = "ury";
  set<int> values;
  int pos = main.find(value, 0);
  while (pos != string::npos) {
    values.insert(pos);
    pos = main.find(value, pos + 1);
  }
  cout << "the values are " << endl;
  for (set<int>::iterator it = values.begin(); it != values.end(); it++)
    cout << *it << endl;
  return 0;
}