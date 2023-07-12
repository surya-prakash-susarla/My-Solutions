#include <iostream>
#include <map>
using namespace std;
bool fin(int key, map<int, int> f) {
  if (f.find(key) == f.end()) {
    return false;
  } else {
    cout << "The value is as follows: " << f[key] << endl;
    return true;
  }
}
int main() {
  int qn;
  cin >> qn;
  map<int, int> f;
  for (int i = 0; i < qn; i++) {
    int m, n;
    cin >> m >> n;
    f[m] = n;
  }
  map<int, int>::iterator i;
  for (i = f.begin(); i != f.end(); i++)
    cout << (*i).first << "\t" << (*i).second << endl;
  cout << "Enter an element to search" << endl;
  int key;
  cin >> key;
  cout << "TRUE=" << true << " FALSE=" << false << endl;
  cout << fin(key, f);
  return 0;
}
