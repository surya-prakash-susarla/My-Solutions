#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int find ( int x , int y , vector<vector<int>>& grid ) {
        if ( x < 0 or y < 0 or x == grid.size() or y == grid[0].size() or grid[x][y] == 0 )
            return 0;
        grid[x][y] = 0;
        int top = find ( x-1,y,grid) , bottom = find(x+1,y,grid) , left = find(x,y-1,grid) , right = find(x,y+1,grid) ;
        
        return 1+top+bottom+left+right ;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_value = 0 ;
        for ( int i=0 ; i<grid.size() ; i++ )
            for ( int j=0 ; j<grid[0].size() ; j++ )
                if ( grid[i][j] == 1 )
                    max_value = max ( max_value , find ( i , j , grid ) );
        
        return max_value ;
    }
};