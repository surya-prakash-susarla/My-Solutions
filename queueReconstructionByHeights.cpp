bool compare ( const vector<int>& a , const vector<int>& b ) {
    if ( a[0] < b[0] )
        return true ;
    else if ( a[0] == b[0] and a[1] > b[1] )
        return true;
    return false;
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& input ) {
        if ( input.size() == 0 )
            return vector<vector<int>>();
        sort ( input.begin() , input.end() , compare );
        vector<vector<int>> answer ;
        answer.push_back ( input[input.size()-1] );
        
        for ( int i=input.size()-2 ; i > -1 ; i-- ) {
            if ( input[i][1] + answer.begin() == answer.end() )
                answer.push_back ( input[i] );
            else 
                answer.insert ( answer.begin() + input[i][1] , input[i] );
        }
        
        return answer;
    }
};