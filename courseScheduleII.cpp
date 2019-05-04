class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& courses) {
        vector<vector<bool>> req ( n , vector<bool>(n,false) );
        vector<int> req_count ( n , 0 );
        vector<bool> visited ( n , false );
        
        for ( auto i : courses ) {
            req[i[0]][i[1]] = true ;
            req_count [ i[0] ] += 1;
        }
        
        vector<int> answer ;
        
        while ( answer.size() != n ) {
            int index = -1 ;
            for ( int i=0 ; i<n ; i++ ) 
                if ( req_count[i] == 0 and not visited[i] ) {
                    index = i ;
                    visited[i] = true ;
                    break;
                }
            if ( index == -1 )  return vector<int>();
            answer.push_back ( index );
            for ( int i=0 ; i<n ; i++ )
                if ( req[i][index] ) {
                    req[i][index] = false ;
                    req_count[i] -= 1;
                }    
        }
        return answer; 
    }
};