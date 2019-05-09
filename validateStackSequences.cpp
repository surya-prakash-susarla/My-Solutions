#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> input ;
        int push_index = 0 , pop_index = 0 ;
        while ( pop_index < popped.size() ) {
            if ( not input.empty() and input.top() == popped[pop_index] ) {
                input.pop() ;
                pop_index += 1;
            }            
            else {
                if ( push_index < pushed.size() ) 
                    input.push ( pushed[push_index++] );
                else
                    return false;
            }
        }
        if ( not input.empty () or push_index < pushed.size() ) return false;
        return true;
    }
};