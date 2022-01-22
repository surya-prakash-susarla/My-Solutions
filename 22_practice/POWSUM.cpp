#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

#include <bitset>

#define in scanf
#define out printf

using namespace std;

// Problem:

typedef long long int llint;
typedef long double ldouble;

llint __maxbit__(int value) {
  if (value == 0)
    return 0;
  llint bits = 0;
  while (value >>= 1)
    bits++;
  return 1 << ++bits;
}

void __calc__() {
  llint n;
  cin >> n;
  vector<int> values(n);
  int sum = 0;
  int minval = numeric_limits<int>::max();
  int minval_location = -1;
  for (llint i = 0; i < n; i++) {
    cin >> values[i];
    sum += values[i];
    if ( values[i] < minval ) {
      minval = values[i];
      minval_location = i ;
    }
  }

  bitset<64> temp (sum) ; 
  if ( temp.count() == 1 )  {
    cout << 0 ;
    return;
  }

  int diff = __maxbit__(sum) - sum;

  // cout << "diff required : " << diff << endl;

  cout << 1 << endl;
  cout << 1 << " " << (diff / minval) + 1 << endl;
  cout << minval_location+1 ;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  llint t;
  cin >> t;
  while (t--) {
    __calc__();
    cout << endl;
  }

  return 0;
}
