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
    int numRescueBoats(vector<int>& values, int limit) {
         sort(values.begin(), values.end());

         int n = values.size();
         
         int left = 0;
         int right = n-1;

         int answer = 0;
         while ( left < right ) {
             if ( values[right] + values[left] <= limit ) {
                 left++;
                 right--;
             } else {
                 right--;
             }
             answer++;
         }

         if ( left == right )   answer++;

         return answer;
    }
};

int main() {

    ios_base::sync_with_stdio(false); 


    return 0;
}

