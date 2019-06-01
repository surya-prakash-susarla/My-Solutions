#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int calc ( int index , vector<bool>& visited , const vector<vector<int>>& stones ) {
        int count = 1 ;
        visited[index] = true;
        for ( int i=0 ; i<stones.size() ; i++ ){
            if ( not visited[i] and (stones[i][0] == stones[index][0] or stones[i][1] == stones[index][1] ) ) {
                count += calc ( i , visited , stones );
            }
        }
        return count;
    }
    
    int find ( const vector<bool> visited ) {
        for ( int i=0 ; i<visited.size() ; i++ )
            if ( not visited[i] )   return i;
        return -1;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        vector<bool> visited ( stones.size() , false );
        int answer = 0 , index = find ( visited );
        while ( index != -1 ) {
            int group = calc ( index , visited , stones );
            answer += ( group-1 );
            index = find ( visited );
        }
        return answer;
    }
};