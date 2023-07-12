#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
typedef long long int llint;
int main() {
  llint n;
  cin >> n;
  map<string, llint> a;
  for (llint i = 0; i < n; i++) {
    llint type;
    string name;
    cin >> type >> name;
    if (type == 1) {
      llint marks;
      cin >> marks;
      map<string, llint>::iterator it;
      it = a.find(name);
      if (it != a.end()) {
        it->second += marks;
      } else {
        a.insert(make_pair(name, marks));
      }
    } else if (type == 2) {
      a.find(name)->second = 0;
    } else {
      map<string, llint>::iterator it;
      it = a.find(name);
      if (it != a.end())
        cout << it->second << endl;
      else
        cout << "0" << endl;
    }
  }
  cout << "exiting the for loop" << endl;
  return 0;
}
