#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int input) {
        typedef vector<int> vint;
        typedef vector<vint> vvint;
        
        vvint answer;
        answer.push_back({1});
        if ( input >= 2 )   answer.push_back({1,1});
        
        for(int i=2 ; i < input ; i++ ) {
            vint temp = {1};
            for(int j=1 ; j<answer[i-1].size() ; j++)
                temp.push_back(answer[i-1][j] + answer[i-1][j-1]);
            temp.push_back({1});
            answer.emplace_back(temp);
        }
        
        return answer;
    }
};

