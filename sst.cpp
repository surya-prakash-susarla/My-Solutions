#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[]) {
  int n;
  while (scanf("%d", &n) == 1) {
    int t;
    cin >> t;
    vector<int> a;
    for (int i = 0; i < t; i++) {
      string s;
      int f;
      cin >> s;
      // cout<<"HERE I am";
      if (s == "CLOSEALL") {
        // cout<<"IN ERASE statement"<<endl;
        a.erase(a.begin(), a.end());
        // cout<<a.size()<<endl;
      } else if (s == "CLICK") {
        cin >> f;
        if (find(a.begin(), a.end(), f) != a.end()) {
          a.erase(remove(a.begin(), a.end(), f), a.end());
        } else
          a.push_back(f);
      }
      cout << a.size() << endl;
    }
    // cout<<"___________________________________________________________________"<<endl;
  }
  return 0;
}
