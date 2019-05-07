#include <bits/stdc++.h>
using namespace std;

typedef long double ld ;
typedef long long int llint ;

#define point pair<llint,llint>

ld calc ( llint& n , vector<point>& input ) {
    llint min_distance = numeric_limits<llint>::max() ;
    for ( llint i=0 ; i<n ; i++ ) {
        point current = input[i];
        for ( llint j=i+1 ; j<n ; j++ ) {
            point compare = input[j];
            llint y_values = compare.second - current.second , x_values = compare.first - current.first , slope = 0 ;
            if ( abs(x_values) == abs(y_values) )
                return 0; 
            else 
                min_distance = min ( min_distance , 
                                min ( abs ( compare.first - compare.second - current.first + current.second ) , 
                                      abs ( compare.first + compare.second - current.first - current.second ) 
                                    ) ) ;
        }
    }
    return (ld) min_distance / 2 ; 
}

int main() {
    llint t ;
    cin >> t; 
    point temp ;
    while ( t-- > 0 ) {
        llint n; 
        cin >> n ;
        vector<point> input ;
        for ( llint i=0 ; i<n ; i++ ) {
            cin >> temp.first >> temp.second ;
            input.push_back ( temp );
        }
        cout << fixed << setprecision ( 7 ) << showpoint << calc ( n , input );
        if ( t+1 > 1 )  cout << endl ;
    }
    return 0;
}