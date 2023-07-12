#include <algorithm>
#include <iostream>
#include <tuple>
using namespace std;
int main() {
  vector<tuple<int, int, int, bool>> v;
  int n;
  cout << "enter the size" << endl;
  cin >> n;
  cout << "enter the values as following:\nint,int,int" << endl;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    int a, b, c;
    bool d;
    if (i % 2 == 0)
      d = true;
    else
      d = false;
    cin >> a >> b >> c;
    get<0>(v[i]) = a;
    get<1>(v[i]) = b;
    get<2>(v[i]) = c;
    get<3>(v[i]) = d;
  }
  cout << "enter the value to be searched" << endl;
  int se1, se2, se3;
  cin >> se1 >> se2 >> se3;
  auto it = find_if(
      v.begin(), v.end(), [se1, se2, se3](const tuple<int, int, int, bool> &e) {
        return get<0>(e) == se1 and get<1>(e) == se2 and get<2>(e) == se3;
      });
  if (it != v.end()) {
    cout << "found the element" << endl;
    cout << "the corresponding boolean is " << endl;
    cout << get<3>(*it) << endl;
  } else
    cout << "not found" << endl;
  return 0;
}
