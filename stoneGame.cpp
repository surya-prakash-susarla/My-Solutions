class Solution {
public:
    
    vector<vector<int>> a_memo , b_memo ;
    int limit_value = numeric_limits<int>::max();
    
    int alex_play ( int a_values , int b_values , int start , int stop , const vector<int>& stones )        {
        if ( start > stop )
            return a_values - b_values ;  
        
        if ( this->a_memo[start][stop] != limit_value )
            return this->a_memo[start][stop] + a_values - b_values ;
        
        int first_pick = opp_play ( stones[start] , 0 , start+1 , stop , stones );
        int last_pick = opp_play ( stones[stop] , 0 , start , stop-1 , stones );
        
        
        this->a_memo[start][stop] = max ( first_pick , last_pick );
        
        return max ( first_pick, last_pick )  + a_values - b_values  ;
    }
    
    int opp_play ( int a_values , int b_values , int start , int stop , const vector<int>& stones ) {
        if ( start > stop )
            return a_values - b_values ;
        
        if ( this->b_memo[start][stop] != limit_value )
            return this->b_memo[start][stop] + a_values - b_values ;
        
        int first_pick = alex_play ( 0 , stones[start] , start+1 , stop , stones );
        int last_pick = alex_play ( 0 , stones[stop] , start , stop-1 , stones );
        
        this->b_memo[start][stop] = min ( first_pick , last_pick );
        
        return min ( first_pick , last_pick )  + a_values - b_values ;
    }
    
    bool stoneGame(vector<int>& piles) {
        this->a_memo.resize ( piles.size() , vector<int>(piles.size() , limit_value ) );
        this->b_memo.resize ( piles.size() , vector<int>(piles.size() , limit_value ) );
        int answer = alex_play ( 0 , 0 , 0 , piles.size()-1 , piles );
        if ( answer > 0 ) 
            return true ;
        return false;
    }
};