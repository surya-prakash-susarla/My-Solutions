class Solution {
public:
    
    int min_value = numeric_limits<int>::max() , target ;
    vector<int> input ;
    
    void calc ( int lag , int lead , int current ) {
        
        if ( lead >= input.size() )
            return ;
        
        current += input[lead];
        
        if ( current < target )
            calc ( lag , lead+1 , current );
        else {
            while ( lag <= lead and current >= target ) {
                current -= input[lag];
                lag += 1 ;
            }
            lag -= 1; 
            current += input[lag];
            min_value = min ( min_value , lead-lag+1 );
            calc ( lag , lead+1 , current );
        }
        return;
    }
    
    int minSubArrayLen( int s, vector<int>& values ) {
        target = s ;
        input = values ;
        calc ( 0 , 0 , 0 );
        if ( min_value == numeric_limits<int>::max() )  return 0 ;
        return min_value ;
    }
};