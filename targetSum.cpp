class Solution {
public:
    
    int ways ( int index , int target , vector<int> nums , vector<map<int,int> >&memo ){
        if ( index == nums.size()-1 ){
            if ( target == 0 and nums[index]==0 )   return 2;
            else if ( target == nums[index] or target == 0-nums[index] ) return 1;
            else    return 0;
        }
        if ( memo[index].find(target) != memo[index].end() )    return memo[index][target];
        int pos = ways ( index+1, target-nums[index] , nums , memo );
        int neg = ways ( index+1, target+nums[index] , nums , memo );
        memo[index].insert(make_pair(target,pos+neg));
        return memo[index][target];
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<map<int,int> > memo (nums.size());
        return ways ( 0 , S , nums  , memo );
    }
};