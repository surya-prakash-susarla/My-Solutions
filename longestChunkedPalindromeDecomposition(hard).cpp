class Solution {
public:
    
    bool matchStrings ( int index1 , int index2 , const int& length , const string& value ) {
        int i=-1 ; 
        while ( ++i < length )
            if ( value[index1+i] != value[index2+i] )
                return false ;
        return true; 
    }
    
    int longestDecomposition(string text) {
        map<char,vector<int>> alpha_locs ;
        for ( int i=text.size()-1 ; i>-1 ; i-- )
            alpha_locs[text[i]].push_back ( i );
        int start = 0 , end = text.size()-1 , count = 0 ;
        while ( start < end and start < text.size()/2 + 1 ) {
            int prev_start = start ;
            for ( int a_i : alpha_locs[text[start]] )
                if ( a_i <= end && a_i != start )
                    if ( matchStrings ( start , a_i , end-a_i+1 , text) ) {
                        count += 2; 
                        start += end-a_i+1 ;
                        end -= end-a_i+1 ;
                        break;
                    }
            if ( start == prev_start )
                return count + 1;
        }
        if ( end - start  >= 0 )
            return count + 1;
        return count ;
    }
};