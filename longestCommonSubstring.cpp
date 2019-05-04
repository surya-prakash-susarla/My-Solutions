#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& a, vector<int>& b) {
        
        vector<vector<int>> memo ( a.size() , vector<int> ( b.size() , 0 ) );
        int max_value = 0 ;
        
        for ( int i=0 ; i<a.size() ; i++ )
            for ( int j=0 ; j<b.size() ; j++ ) {
                if ( a[i] == b[j] ) {
                    if ( i == 0 or j == 0 ) memo[i][j] = 1 ;
                    else    memo[i][j] = memo[i-1][j-1]+1 ;
                    if ( memo[i][j] > max_value )   max_value = memo[i][j];
                }
            }
        
        return max_value ;
    }
};