#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        map<int, int> values;
        for ( int i : nums )    values[i]++;
        
        vector<int> answer;
        
        for(int i: queries) {
            int req = i ; 
            int temp_answer = 0 ;
            
            for ( auto it = values.begin() ; it!=values.end() ; it++ ) {
                if ( it->first > req )  break;
                
                int k = min ( req / it->first , it->second );
                temp_answer +=  k;
                req -= it->first * k ;
                
            }
            
            answer.push_back(temp_answer);
        }
        
        return answer;
    }
};


int main() {


    return 0;
}

