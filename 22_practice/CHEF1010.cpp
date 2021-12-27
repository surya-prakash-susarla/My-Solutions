#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <utility>
#include <map>
#include <stack>
#include <memory>
#include <cmath>
#include <set>
#include <unordered_map>
#include <tuple>

#define in scanf
#define out printf

// Problem: 

typedef long long int llint;
typedef long double ldouble;

using namespace std;

llint __calc__() {
  llint n ; 
  cin >> n; 
  vector<llint> values(n);
  for ( llint i=0 ; i<n ; i++)
    cin >> values[i];
  sort ( values.begin() , values.end() );

  return (values[n-1] - values[0]) * values[n-2];
}

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  llint t; 
  cin >> t; 
  for ( llint i=0 ; i<t ; i++ ){
    cout << __calc__()  ; 
    if ( i < t-1 )  cout << endl;
  }

  return 0;
}
