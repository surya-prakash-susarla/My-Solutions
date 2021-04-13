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
#include <queue>

// Problem: 

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
public:
    bool isValid(string s) {
      stack<char> st ; 
      
      for ( const char& i : s ) {
        if ( i == ')' ) {
          if ( !st.empty() &&  st.top() == '(' )  st.pop() ;
          else return false ;
        }
        else if ( i == ']' ) {
          if ( !st.empty() && st.top() == '[' )  st.pop() ;
          else return false ;
        }
        else if ( i == '}' ) {
          if ( !st.empty() && st.top() == '{' )  st.pop() ;
          else return false ;
        } else 
          st.push(i);
      }

      return st.empty();

    }
};

int main(){
  std::ios_base::sync_with_stdio(false);
  
  return 0;
}
