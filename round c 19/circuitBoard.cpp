#include <bits/stdc++.h>
using namespace std;

typedef long long int llint;

llint calc ( void ) {
    llint r , c , req ;
    cin >> r >> c >> req ;
    vector<vector<llint>> grid ( r , vector<llint>(c) );
    for ( llint i=0 ; i<r ; i++ ) 
        for ( llint j=0 ; j<c ; j++ )
            cin >> grid[i][j] ;
    llint min_value = -1 , max_value = -1 ;
    for ( llint i=0 ; i<r ; i++ )
        for ( llint j=0 ; j<c ; j++ ) {
            llint count = 1; 
            min_value = grid[i][j] , max_value = grid[i][j] ;
            for ( llint k = j+1 ; k<c ; k++ ) {
                min_value = min ( min_value , grid[i][k] ) , max_value = max ( max_value , grid[i][k] ) ;
                if ( max_value - min_value <= req ) count += 1;
                else break ;
            }
            grid[i][j] = count ;
        }
    llint answer = -1 ; 
    for ( llint j=0 ; j<c ; j++ )
        for ( llint i=0 ; i<r ; i++ ) {
            llint min_value = grid[i][j] ;
            answer = max ( answer , min_value );
            for ( llint k = i+1 ; k<r ; k++ ) {
                min_value = min ( min_value , grid[k][j] );
                answer = max ( answer , min_value * ( k - i + 1 ) );
            }
        }
    return answer ;
}

int main() {
    llint t;
    cin >> t; 
    for ( llint i=1 ; i<=t ; i++ ) {
        llint answer = calc () ;
        cout << "Case #" << i << ": " << answer ;
        if ( i < t )    cout << endl ;
    }
    return 0;
}