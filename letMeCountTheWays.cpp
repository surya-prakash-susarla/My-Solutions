#include <iostream>
#include <vector>

// DOES NOT WORK WITHOUT DP ( DP WORKS ONLY FOR SMALL TESTSET )

using namespace std;
typedef long long int llint ;

llint calc ( llint singles , llint married , llint rem_married , bool prev_type ) {
    if ( singles <0 or married < 0 or rem_married < 0 ) return 0;
    if ( singles == 0 and married == 0 and rem_married == 0 )   return 1 ;
    llint single_placed = 0 ;
    if ( singles >= 1 )
        single_placed = calc ( singles-1 , married , rem_married , false ) * singles ;
    llint new_married_placed = 0;
    if ( married >= 2 ) 
        new_married_placed = calc ( singles , married-2 , rem_married+1 , true ) * married ;
    llint prev_married_placed = 0;
    if ( prev_type and rem_married > 1 )
        prev_married_placed = calc ( singles , married , rem_married-1 , false ) * ( rem_married - 1 );
    else if ( not prev_type and rem_married >= 1 )
        prev_married_placed = calc ( singles , married , rem_married - 1 , false ) * rem_married ;
    return single_placed + new_married_placed + prev_married_placed ;
}

int main(){
    llint t;
    cin >> t; 
    for(llint i=1 ; i<=t ; i++ ) {
        llint m , n ;
        cin >> m >> n ;
        llint answer = calc ( 2*(m-n) , 2*n , 0 , false );
        cout << "Case #"<<i<<": " << answer << endl;
    }
    return 0;
}