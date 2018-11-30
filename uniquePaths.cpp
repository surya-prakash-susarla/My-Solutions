class Solution {
public:
    
    int find_ways ( int i , int j , vector<vector<int> > &grid , int m, int n ){
        if ( i==m-1 and j==n-1 )    return 1;
        if ( i>=m or i<0 or j>=n or j<0 )   return 0;
        if ( grid[i][j]!=-1 )   return grid[i][j];
        grid[i][j] = find_ways(i+1,j,grid,m,n) + find_ways(i,j+1,grid,m,n);
        return grid[i][j];
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int> >grid(m,vector<int>(n,-1));
        return find_ways(0,0,grid,m,n);
    }
};