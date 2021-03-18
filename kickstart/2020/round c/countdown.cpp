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

#define in scanf
#define out printf

// Problem: 

typedef long long int llint;
typedef long double ldouble;

llint __calc__ () {
  llint n , k ;
  std::cin >> n >> k ;
  llint current_k = k ;
  llint temp = -1 ; 
  llint answer = 0 ;
  for ( llint i=0 ; i<n ; i++ ) {
    std::cin >> temp ; 
    if ( temp == current_k ) {
      current_k--;
      if ( current_k == 0 ) {
        answer++ ;
        current_k = k ;
      }
    } else {
      if ( temp == k )
        current_k = k-1 ;
      else 
        current_k = k ;
    }
  }
  return answer;
}


int main(){
  std::ios_base::sync_with_stdio(false);
  
  llint t;
  std::cin >> t;
  for ( llint i=1 ; i<=t ; i++ ){
    llint answer = __calc__ ();
    std::cout << "Case #" << i << ": " << answer << "\n" ;
  }

  return 0;
}
