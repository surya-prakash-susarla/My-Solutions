#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    
    int calc ( int index , const vector<int>& input ) {
        if ( index >= input.size() - 2 )    return 0 ;
        int common_diff = input[index+1] - input[index] , score = 0;
        index +=1 ;
        for ( int i=index+1 ; i<input.size() ; i++ ) 
            if ( input[i] - input[i-1] == common_diff )
                score++ ; 
            else 
                break ;
        return score ;
    }
    
    int numberOfArithmeticSlices(const vector<int>& input) {
        if ( input.size() < 3 )    return 0 ;
        int answer = 0 ;
        for ( int i=0 ; i<input.size()-2 ; i++ )
            answer += calc ( i , input );
        return answer ;
    }
};