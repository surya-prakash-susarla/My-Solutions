#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1 , zero = 0 , index = -1 ; 
        vector<int> answer ( nums.size() , 0 );
        for ( int i=0 ; i<nums.size() ; i++ )
            if ( nums[i] == 0 ) zero += 1 , index = i ; 
            else product *= nums[i];
        if ( zero > 1 ) return answer ;
        else if ( zero == 1 ) {
            answer[index] = product ;
            return answer ;
        }
        for ( int i=0 ; i<nums.size() ; i++ )
            answer[i] = product / nums[i];
        return answer; 
    }
};