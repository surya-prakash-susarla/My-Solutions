#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int calc ( vector<int>::iterator it , vector<int>& memo , vector<int>& input , const int& len ) {
        if ( it >= input.end() )
            return 0;
        if ( memo[it-input.begin()] != -1 ) 
            return memo[it-input.begin()];
        int answer = -1 ;
        for ( int i=1 ; i<=len ; i++ ){
            vector<int>::iterator end_value = it + i ;
            int size = i ;
            if ( end_value >= input.end() ) { 
                end_value = input.end() ;
                size = input.end() - it ;
            }
            int max_value = *max_element ( it , end_value );
            int current_value = size * max_value ;
            
            answer = max ( answer , current_value + calc ( end_value , memo , input , len ) ) ;
        }
        memo[it-input.begin()] = answer ;
        return answer ;
    }
    
    int maxSumAfterPartitioning(vector<int>& input, int len) {
        vector<int> memo ( input.size() , -1 );
        return calc ( input.begin() , memo , input , len );
    }
};