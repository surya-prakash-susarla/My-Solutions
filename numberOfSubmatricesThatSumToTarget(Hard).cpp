
class Solution {
public:

    int numSubmatrixSumTarget(vector<vector<int>>& input, int target) {
        vector<vector<int>> sum_values( input.size() , vector<int>( input[0].size() , 0 ) ) ;
        for ( int i=0 ; i<input.size() ; i++ ) {
            int row_sum = 0 ;
            for ( int j=0 ; j<input[0].size() ; j++ ){
                row_sum += input[i][j] ; 
                sum_values[i][j] = row_sum ;
            }
        }
        int answer = 0 ;
        for ( int i=0 ; i<input.size() ; i++ )
            for ( int j=0 ; j<input[0].size() ; j++ )
                for ( int col_size = 0 ; j+col_size < input[0].size() ; col_size++ ){
                    int init_sum = 0 ;
                    bool prev_exists = j >= 1 ? true : false;
                    for ( int k=i ; k<input.size() ; k++ ){
                        init_sum += sum_values[k][j+col_size] - (prev_exists?sum_values[k][j-1]:0);
                        if ( init_sum == target )   answer++;
                    }
                }
        return answer;
    }
};