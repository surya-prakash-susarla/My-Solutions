class Solution {
public:
    vector<int> partitionLabels(string input) {
        vector<int> last_indices ( 26 , -1 );
        for ( int i=0 ; i<input.size() ; i++ )
            last_indices [ input[i]-'a' ] = i ;
        vector<int> answer;
        int start_index = 0 ;
        while ( start_index < input.size() ) {
            int max_index = last_indices[input[start_index]-'a'];    
            for ( int i=start_index+1 ; i<max_index ; i++ )
                if ( last_indices[input[i]-'a'] > max_index )
                    max_index = last_indices[input[i]-'a'];
            answer.push_back ( max_index - start_index + 1 );
            start_index = max_index  + 1; 
        }   
        return answer;
    }
};