bool compare ( const pair<int,vector<int>>& a , const pair<int,vector<int>>& b ){
    return a.first < b.first ;
}
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int x, int y) {
        vector< pair<int,vector<int> > > answer ;
        for ( int i = 0 ; i < rows ; i++ )
            for ( int j=0 ; j<cols ; j++ )
                answer.push_back ( make_pair ( abs(i-x)+abs(j-y) , vector<int>{i,j} ) );
        sort ( answer.begin() , answer.end() , compare );
        vector<vector<int>> answer_value ;
        for ( int i=0 ; i<answer.size() ; i++ )
            answer_value.push_back ( answer[i].second );
        return answer_value;
    }
};