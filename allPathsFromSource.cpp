class Solution {
public:
    
    vector<vector<int>> findPath ( int current , vector<vector<int>> cons , vector<bool> covered, vector<vector<vector<int>>>& memo ){
        if ( current == cons.size()-1 )
            return vector<vector<int>>(1,vector<int>(1,current));
        if ( covered[current] )
            return memo[current];
        covered[current] = true;
        vector<vector<int>> answer ;
        
        for ( auto node : cons[current] )
            if ( not covered[node] ) {
                auto forwardPath = findPath ( node , cons , covered , memo );
                for ( auto j : forwardPath ){
                    j.push_back ( current );
                    answer.push_back ( j );
                }
            }
        
        memo[current] = answer;
        return answer;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<vector<int>>> memo (graph.size());
        auto answer = findPath ( 0 , graph , vector<bool>(graph.size(),false) , memo );
        for ( int i=0 ; i<answer.size() ; i++ )
            reverse(answer[i].begin(),answer[i].end());
        return answer;
    }
};