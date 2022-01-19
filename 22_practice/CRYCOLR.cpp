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

inline bool __is_done__(const vector<vector<llint>>& values , const int n ) {
  return values[0][0] == n and values[1][1] == n and values[2][2] == n;
}

void __print__ ( const vector<vector<llint>>& values ) {
  for ( const vector<llint>& i: values ) {
    for ( const llint& j : i )
      cout << j << " " ; 
    cout << endl;
  }
  return;
}


llint __calc__() {
  llint n ; 
  cin >> n ;
  vector<vector<llint>> values (3, vector<llint>(3));

  for ( llint i=0 ; i<3 ; i++ )
    for ( llint j=0 ; j<3 ; j++ )
      cin >> values[i][j];
  
  if ( __is_done__(values, n) ) return 0 ;

  // direct trades.
  // 0 to 1
  auto dtrade = [&](int col_a, int col_b, int box_a, int box_b) -> llint {
    llint swap_min = min(values[box_a][col_b], values[box_b][col_a]);

    values[box_a][col_a] += swap_min ; 
    values[box_a][col_b] -= swap_min ;
    values[box_b][col_a] -= swap_min ;
    values[box_b][col_b] += swap_min ;

    return swap_min;
  };

  // cout << "inital values : " << endl;
  // __print__(values);

  llint answer = 0 ;
  answer += dtrade(0, 1, 0, 1);
  // cout << "after 1st dtrade : " << endl;
  // __print__(values);

  answer += dtrade(1, 2, 1, 2);
  // cout << "after 2nd dtrade : " << endl;
  // __print__(values);

  answer += dtrade(0, 2, 0, 2);
  // cout << "after 3rd dtrade : " << endl;
  // __print__(values);


  // cout << "values after direct trade completion : " << endl;
  // __print__(values);

  // cout << "==== answer after direct trades : " << answer << endl;

  return answer += ( values[0][1] + values[0][2]) * 2;

}

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  llint t ; 
  cin >> t;
  while ( t-- ) {
    cout << __calc__() << endl;
  }

  return 0;
}
