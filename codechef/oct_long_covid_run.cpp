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

using namespace std;

typedef long long int llint;
typedef long double ldouble;

int main()
{
    llint t;
    cin >> t;
    for (llint i = 0; i < t; i++)
    {
        llint n, k, x, y;
        cin >> n >> k >> x >> y;

        vector<bool> values ( n , false );
        values[x] = true ; 

        llint start =  ( x + k ) % n ;
        while ( !values[start] ) {
            values[start] = true ; 
            start = (start+k) % n; 
        }

        if ( values [y] )
            cout << "YES" ; 
        else 
            cout << "NO" ;
        
        if ( i < t-1 )
            cout << endl;
    }

    return 0;
}