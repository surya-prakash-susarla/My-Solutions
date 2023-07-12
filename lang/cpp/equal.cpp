#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int llint;
#define pb push_back
llint size;
vector<llint> a;
bool all_equal(vector<llint> a) {
  vector<llint>::iterator it;
  llint temp = a[0];
  for (it = a.begin(); it != a.end(); it++)
    if (*it != temp)
      return false;
  return true;
}
vector<llint> adder(vector<llint> a, llint pos, llint value) {
  for (vector<llint>::iterator it = a.begin(); it != a.end(); it++)
    if (it - a.begin() != pos)
      *it += value;
  return a;
}
bool solution(llint n, vector<llint> a) {
  bool equality = all_equal(a);
  if (equality)
    return true;
  if (n == size and not equality)
    return false;
  return solution(n + 1, adder(a, n, 1)) or solution(n + 1, adder(a, n, 2)) or
         solution(n + 1, adder(a, n, 5));
}

int main() {
  llint t;
  cout << "enter the number of test cases" << endl;
  cin >> t;
  while (t-- > 0) {
    cout << "enter the number of values" << endl;
    cin >> size;
    cout << "enter the values" << endl;
    for (llint i = 0; i < size; i++) {
      llint temp;
      cin >> temp;
      a.pb(temp);
    }
    if (solution(0, a))
      cout << "all chocolates can be distributed equally" << endl;
    else
      cout << "no they cannot be distributed equally" << endl;
  }
  return 0;
}
