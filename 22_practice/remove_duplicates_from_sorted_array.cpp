#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int maxvalue = numeric_limits<int>::max();
        
        int last_repeat = nums[0];
        int repeat_count = 0;
        for ( int i = 1 ; i<nums.size() ; i++ )
            if ( nums[i] == last_repeat )   {nums[i] = maxvalue ; repeat_count++ ;}
            else    last_repeat = nums[i];
        
        sort(nums.begin(), nums.end());
        
        return nums.size() - repeat_count; 
        
    }
};

