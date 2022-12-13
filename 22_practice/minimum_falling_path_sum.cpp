class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& values) {
        vector<int> last_values = *values.rbegin();
        
        // cout << "last values initial : " << endl;
        // for ( int i : last_values )     cout << i << " " ;
        // cout << endl;

        int n = values.size();
        for(int i=n-2 ; i>-1 ; i--) {
            vector<int> temp = values[i];
            for(int j=0 ; j<temp.size(); j++ ) {
                temp[j] = min({
                    j > 0 ? temp[j] + last_values[j-1] : numeric_limits<int>::max(),
                    j < temp.size()-1 ? temp[j] + last_values[j+1] : numeric_limits<int>::max(),
                    temp[j] + last_values[j]
                });
            }
            swap(last_values, temp);
            // cout << "last values at iteration : " << i << endl;
            // for ( int i : last_values )     cout << i << " ";
            // cout << endl;
        }
        return *min_element(last_values.begin(), last_values.end());
    }
};
