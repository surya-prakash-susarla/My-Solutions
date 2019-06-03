#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void calc ( int index , vector<bool>& visited , const vector<vector<int>>& input ) {
        visited[index] = true ;
        for ( int i=0 ; i<input.size() ; i++ )
            if ( input[index][i] and not visited[i] )
                calc ( i , visited , input );
        return;
    }
    
    int getIndex ( const vector<bool>& visited ) {
        for ( int i=0 ; i<visited.size() ; i++ )
            if ( not visited[i] )   return i ;
        return -1;
    }
    
    int findCircleNum(vector<vector<int>>& input ) {
        vector<bool> visited ( input.size() , false );
        int answer = 0 , init = getIndex ( visited ) ;
        while ( init != -1 ) {
            calc ( init , visited , input );
            answer ++ ;
            init = getIndex ( visited );
        }
        return answer;
    }
};