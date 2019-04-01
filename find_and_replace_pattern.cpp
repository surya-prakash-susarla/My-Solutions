class Solution {
public:
    
    bool comp ( string a , string b ) {
        if ( a.size() != b.size() )
            return false;
        unordered_map < char, char > values; 
        vector<bool> used ( 26, false );
        for ( int i=0 ; i<a.size() ; i++ )
            if ( values.find ( a[i] ) != values.end() )
                if ( values[a[i]] != b[i] ) 
                    return false;
            else if ( used[b[i]-'a'] )
                return false;
            else {
                values[a[i]] = b[i];
                used[b[i]-'a'] = true;
            }
        return true;        
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> answer ;
        for ( string i : words )
            if ( comp ( pattern , i ) )
                answer.push_back ( i );
        return answer;
    }
};