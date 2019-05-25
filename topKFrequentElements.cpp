#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort ( nums.begin() , nums.end() ) ;
        vector<int> temp ( nums.size() , 1 );
        for ( int i=1 ; i<nums.size() ; i++ )
            if ( nums[i] == nums[i-1] )
                temp[i] = temp[i-1]+1;
        map<int,int> values ;
        for ( int i=0 ; i<nums.size() ; i++ )
            values[nums[i]] = temp[i];
        map<int,vector<int>> reversedValues ;
        for ( auto i : values )
            reversedValues[ i.second ].push_back ( i.first ) ;
        vector<int> answer ;
        for ( auto it = reversedValues.rbegin() ; it != reversedValues.rend() and k>0 ; it ++ ) {
            int init = answer.size() ;
            if ( it->second.size() < k )
                answer.insert ( answer.end()  ,it->second.begin() , it->second.end() );
            else 
                for ( int i=0 ; i<k ; i++ )
                    answer.push_back ( it->second[i] );
            k = k - (answer.size() - init );
        }
        return answer ;
        
    }
};