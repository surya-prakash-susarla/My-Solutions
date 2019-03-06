class Solution {
public:
    bool canJump(vector<int>& nums) {
       int bigIndex = 0;
        for ( int i=0 ; i<=bigIndex ; i++ ){
            if ( bigIndex >= nums.size()-1 )    return true;
            bigIndex = max ( bigIndex , i+nums[i] );
        }
        return false;
    }
};
