#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void mark ( int x , int y , vector<vector<int>>& input , vector<pair<int,int>>& boundary ) {
        if ( x < 0 or y < 0 or x == input.size() or y == input[0].size() 
            or input[x][y] == 0 or input[x][y] == -1 )
            return ;
        if ( x-1 >= 0 and input[x-1][y] == 0 )   boundary.push_back ( {x,y} ) ;
        else if ( y-1 >= 0 and input[x][y-1] == 0 ) boundary.push_back ( {x,y} );
        else if ( x+1 < input.size() and input[x+1][y] == 0 )   boundary.push_back ( {x,y} );
        else if ( y+1 < input[0].size() and input[x][y+1] == 0 )    boundary.push_back ( {x,y} );
        input[x][y] = -1 ;
        mark ( x-1 , y , input , boundary );
        mark ( x+1 , y , input , boundary );
        mark ( x , y-1 , input , boundary );
        mark ( x , y+1 , input , boundary );
    }
    
    
    int shortestBridge(vector<vector<int>>& input ) {
        vector<pair<int,int>> first , second ;
        bool marking = true ;
        for ( int i=0 ; i<input.size() ; i++ )
            for ( int j=0 ; j<input[0].size() ; j++ )
                if ( input[i][j] == 1 ) {
                    if ( marking ) {
                        mark ( i , j , input , first );
                        marking = false ;
                    }
                    else 
                        mark ( i , j , input , second );
                }
        int answer = numeric_limits<int>::max() ;
        for  ( pair<int,int> i : first )
            for ( pair<int,int> j : second )
                answer = min ( answer , abs ( i.second - j.second) + abs ( i.first - j.first ) -1 );
        return answer;
    }
};