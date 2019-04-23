class Solution {
public:
    
    bool static compare ( const vector<int>& a , const vector<int>& b ) {
        if ( a[0] - a[1] < b[0] - b[1] )
            return true;
        return false;
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort ( costs.begin() , costs.end() , compare );
        int answer = 0 ;
        for ( int i=0 ; i < costs.size() / 2 ; i++ )
            answer += costs[i][0] , answer += costs[costs.size()-i-1][1];
        return answer;
    }
};