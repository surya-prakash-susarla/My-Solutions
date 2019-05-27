#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string input) {
        for ( int i=1 ; i<input.size() ; i++ ) {
            if ( input[i] == input[i-1] ) {
                input.erase ( i-1 , 2 );
                i -= 2 ;
                if ( i < 0 )    i = 0 ;
            }
        }
        return input ;
    }
};