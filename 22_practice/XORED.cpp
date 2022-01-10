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

using namespace std;

// Problem: 

typedef long long int llint;
typedef long double ldouble;

constexpr int k_upper_limit = 500000;

std::vector<int> __calc__(){
  llint n , d ; 
  cin >> n >> d ;
  int answer = 0 ; 
  vector<int> values(n);
  for ( llint i=0 ; i<n-1 ; i++ ) {
    values[i] = i ; 
    answer ^= i;
  }

  // cout << "initial answer value : " << answer << endl;
  // cout << "d value : " << d << endl ; 
  // cout << "xor value : " << (answer ^ d) << endl;

  answer ^= d; 


  constexpr llint max_value_reachable = 1 << 18 ;

  // cout << "answer value : " << answer << endl;

  if ( answer > k_upper_limit or answer < n-1 ) {
    answer ^= max_value_reachable ; 
    llint temp = n-1 ;
    while ( values[--temp]^max_value_reachable == answer )  ;
    values[temp] ^= max_value_reachable;
  }

  values[n-1] = answer;

  return values ;
}

void __print__(const vector<int>& values ) {
  for ( const int& i : values ) cout << i << " "; 
  cout << endl;
  return;
}

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  llint t;
  cin >> t;
  for ( llint i=0 ; i<t ; i++ ) {
    __print__(__calc__());
  }


  return 0;
}
