#include <iostream>
#include <map>
#include <utility>
using namespace std;
typedef pair<int, int> a;
int main() {
  cout << "enter the size of the data" << endl;
  int n;
  cin >> n;
  map<a, int> f;
  cout << "enter the data" << endl;
  for (int i = 0; i < n; i++) {
    int z, x, c;
    cin >> z >> x >> c;
    f[make_pair(z, x)] = c;
  }
  cout << "data entry complete" << endl;
  cout << "enter a pair to be searched" << endl;
  int pa, pb;
  cin >> pa >> pb;
  cout << "the value is " << f.find(make_pair(pa, pb))->second << endl;
  return 0;
}
