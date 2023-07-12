#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
typedef long long int llint;
#define pb push_back
llint size, g;
vector<llint> times;
vector<tuple<llint, llint, llint, bool>> v;
bool numcal(llint n, llint a, llint b) {
  //	cout<<"checking for values " << n << " " << a << " " << b << endl;
  if (n == size)
    return true;
  if (a > g or b > g)
    return false;
  auto it = find_if(
      v.begin(), v.end(), [n, a, b](const tuple<llint, llint, llint, bool> &e) {
        return get<0>(e) == n and get<1>(e) == a and get<2>(e) == b;
      });
  if (it != v.end())
    return get<3>(*it);
  if (a + times[n] > g and b + times[n] > g) {
    v.push_back(make_tuple(n, a, b, false));
    return false;
  }
  if (a + times[n] > g) {
    bool answer = numcal(n + 1, a, b + times[n]);
    v.push_back(make_tuple(n + 1, a, b + times[n], answer));
    return answer;
  }
  if (b + times[n] > g) {
    bool answer = numcal(n + 1, a + times[n], b);
    v.push_back(make_tuple(n + 1, a + times[n], b, answer));
    return answer;
  }
  return (numcal(n + 1, a + times[n], b) or numcal(n + 1, a, b + times[n]));
}

int main() {
  //	cout<<"enter the number of test cases"<<endl;
  llint t;
  cin >> t;
  while (t-- > 0) {
    //		cout<<"enter the size"<<endl;
    cin >> size;
    //		cout<<"enter the time gap"<<endl;
    cin >> g;
    //		cout<<"enter the data"<<endl;
    // cout<<"\n\nChecker----\n\n"<<size<<" "<<g<<endl;
    for (llint i = 0; i < size; i++) {
      llint temp;
      cin >> temp;
      times.pb(temp);
    }
    //		cout<<"starting search"<<endl;
    if (numcal(0, 0, 0))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    times.clear();
    v.clear();
    //		cout<<"answer complete"<<endl;
  }
  return 0;
}
