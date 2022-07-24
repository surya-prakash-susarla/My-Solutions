#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& values, int target) {
        int rstart = 0;
        int cstart = 0;
        int rend = values.size();
        int cend = values[0].size();

        for(int i=0 ; i<values.size() ; i++)
          if ( values[i][0] > target ) {
            rend = i;
            break;
          }

        if ( rend == 0 )  return false;

        for(int i=0 ; i<values[0].size() ; i++)
          if ( values[0][i] > target ) {
            cend = i;
            break;
          }

        if ( cend == 0 )  return false;

        if ( values[rend-1][cend-1] < target )  return false;

        for(int i=0 ; i<cend ; i++) {
          if ( values[rend-1][i] < target ) 
            cstart = i+1;
        }

        for(int i=0 ; i<rend ; i++) {
          if ( values[i][cend-1] < target )
            rstart = i+1;
        }

        for(int i=rstart ; i<rend ; i++)
          for(int j=cstart ; j<cend ; j++)
            if ( values[i][j] == target )
              return true;

        return false;

    }
};
