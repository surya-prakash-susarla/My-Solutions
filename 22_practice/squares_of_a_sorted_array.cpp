#include <bits/stdc++.h>
using namespace std;

/* test cases 
[-4,-1,0,3,10]
[-7,-3,2,3,11]
[1,2,3,4]
[-3,-2,-1]
*/


class Solution {
public:
    vector<int> sortedSquares(vector<int>& input) {
        vector<int> answer(input.size(), 0);
        
        int pp = 0;
        for ( ; pp < (int)input.size() ; pp++ )  if ( input[pp] >= 0 )   break;
        
        int np = pp - 1;
                
        const int maxvalue = numeric_limits<int>::max();
        
        auto conv = [&](int index) -> int {
            if ( index > -1 ) {
                int temp = 0 - input[index];
                return temp*temp;
            }
            return maxvalue;
        };
        
        int main_index = 0;
        
        while ( np > -1 or pp < input.size() ) {
            int nsq = conv(np);
            int psq = pp < input.size() ? input[pp] * input[pp] : maxvalue ;
            
            if ( nsq < psq ) { 
                answer[main_index++] = nsq ;
                np--;
            } else if ( psq < nsq ) {
                answer[main_index++] = psq ;
                pp++;
            } else if ( psq == nsq and psq != maxvalue ) {
                answer[main_index++] = nsq ;
                answer[main_index++] = psq ;
                np--;
                pp++;
            }
            // cout << "in the while loop, np : " << np << " , pp : " << pp << endl; 
        }
        
        return answer;
    }
};
