class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> values ;
        for ( int i=0 ; i<nums.size() ; i++ ) {
            auto index = find ( nums.begin() , nums.end() , target-nums[i] ); 
            if ( index != nums.end() and index-nums.begin() != i) {
                values.push_back (i) ; 
                values.push_back ( index - nums.begin() );
                return values;
            }
        }
        return values;
    }
};