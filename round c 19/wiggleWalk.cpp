#include <bits/stdc++.h>
using namespace std;

typedef long long int llint ;

pair<llint,llint> calc ( void ) {
    llint n , n_rows , n_cols , r , c ; 
    cin >> n >> n_rows >> n_cols >> r >> c ;
    string instructions ;
    cin >> instructions ;
    r -= 1 , c -= 1;
    vector<vector<bool>> grid ( n_rows , vector<bool> ( n_cols , false ) );
    grid[r][c] = true ;
    for ( char i : instructions ) {
        if ( i == 'E' ) while ( grid[r][c] )    c+=1;
        else if ( i == 'W' )    while ( grid[r][c] )    c-=1;
        else if ( i == 'N' )    while ( grid[r][c] )    r-=1;
        else    while ( grid[r][c] )    r+=1;      
        grid[r][c] = true;
    }
    return {r+1,c+1};
}

int main() {
    llint t; 
    cin >> t; 
    for ( llint i=1 ; i<=t ; i++ ) {
        pair<llint,llint> ret_value = calc () ;
        cout << "Case #"<<i<<": " << ret_value.first << " " << ret_value.second ;
        if ( i < t )    cout << endl ;
    }
    return 0;
}