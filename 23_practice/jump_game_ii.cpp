#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <utility>
#include <limits>
#include <queue>
#include <cmath>
#include <list>
#include <string>
#include <cstdio>
#include <numeric>
#include <stack>

typedef long long int llint;
typedef long long unsigned int ullint;

using namespace std;

class Solution {
public:
    int jump(vector<int>& values) {

        vector<int> temp(values.size(), numeric_limits<int>::max());

        *temp.rbegin() = 0;

       for ( int i=values.size()-2 ; i>-1 ; i-- ) {
           if ( i + values[i] >= values.size() ) {
               temp[i] = 1;
               continue;
           } else {
               for ( int j=values[i] ; j>0 ; j-- ) {
                   if ( temp[i+j] == numeric_limits<int>::max() )
                        continue;
                    temp[i] = min(temp[i], 1+temp[i+j]);
               }
           }
       }

       cout << "final set of temp : " << endl;
       for ( int i : temp ) cout << i << " ";
       cout << endl;

       return temp[0];
    }
};

int main() {

    ios_base::sync_with_stdio(false); 


    return 0;
}

