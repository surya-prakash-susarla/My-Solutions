#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long int llint;

llint answer ( vector<llint> values , llint start , llint stop ){
    llint sum = 0;
    for ( llint i=start+1 ; i <= stop ; i++ )
        sum += values[start] - values[i];
    return sum;
}

llint calc () {
    llint n , p ;
    cin >> n >> p ;
    vector<llint> values ( n );
    for ( llint i=0 ; i<n ; i++ )
        cin >> values[i];
    sort ( values.begin() , values.end() );
    reverse ( values.begin() , values.end() );
    
    
    llint init_sum = 0 , highest = values[0] ;
    for ( llint i=1 ; i<p ; i++ )
        init_sum += highest - values[i] ;
    llint prev_sum = init_sum ;
    for ( llint i=1 ; i <= n-p ; i++ ) {
        llint current_sum = ( prev_sum - (p-1) * ( values[i-1] - values[i] ) ) + ( values[i] - values [ i+p-1 ] );
        if ( current_sum >= 0  and current_sum < init_sum ){
            init_sum = current_sum ;
            highest = values[i];
        }
        prev_sum = current_sum;
    }
    
    return init_sum;
}

int main() {
    llint t;
    cin >> t; 
    for ( llint k=1 ; k<=t ; k++ ) {
        llint answer = calc () ;
        cout << "Case #" << k << ": " << answer << endl;
    }
    return 0;
}