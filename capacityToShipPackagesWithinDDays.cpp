class Solution {
public:
    
    bool sumPossible ( int target , int days , vector<int>& weights ) {
        int sum  =  0 ;
        // cout << "Target : " << target << endl;
        for ( int i=0 ; i<weights.size() ; i++ ) {
            sum = sum + weights[i];
            if ( sum > target ) {
                // cout << sum << endl;
                if ( days == 1 )
                    return false;
                else { 
                    sum = 0 ;
                    days -= 1 ;
                    i-=1;
                }
            }
        }
        
        return true;
        
    }
    
    int shipWithinDays(vector<int>& weights, int D) {
        int min_value = * max_element ( weights.begin() , weights.end() );
        int max_value = accumulate ( weights.begin() , weights.end() , 0 );
        
        for ( int i = min_value ; i<= max_value ; i++ )
            if ( sumPossible ( i , D , weights ) )
                return i ;
        return -1;
    }
};