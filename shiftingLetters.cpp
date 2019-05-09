#include <bits/stdc++.h>
using namespace std;

typedef long long int llint ;

class Solution {
public:
    string shiftingLetters(string input , vector<int>& shifts) {
        llint sum_value = 0 ;
        string answer ; 
        for ( llint i=shifts.size()-1 ; i>-1 ; i-- ) {
            char c = input[i] ;
            sum_value = ( sum_value % 26 + shifts[i] % 26 ) % 26 ;
            llint pos = (int) c + sum_value ;
            if ( pos > 122 )    pos = ( pos%122 )+ 96 ;
            answer = (char)pos + answer ;
        }
        return answer ;
    }
};