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
    inline bool are_connected(const vector<int>& x , const vector<int>& y) {
        float dist = sqrt(pow(x[0]-y[0], 2) + pow(x[1] - y[1],2 ));
        return dist <= x[2];
    }

    int visit ( int index , vector<bool>& visited, const vector<vector<bool>>& connected ) {
        int answer = 1;
        visited[index] = true;
        for ( int i=0 ; i<visited.size() ; i++ ) {
            if ( connected[index][i] and not visited[i] ) {
                answer += visit ( i, visited, connected);
            }
        }
        return answer;
    }

    int maximumDetonation(vector<vector<int>>& input) {
        int n = input.size();

        vector<vector<bool>> connected ( n , vector<bool>(n, false) );

        for ( int i=0 ; i<n ; i++ ) {
            for ( int j=0; j<n ; j++ ) {
                if ( i == j )   continue;
                connected[i][j] = are_connected(input[i], input[j]);
            }
        }
        
        int answer = 1;
        for ( int i=0 ; i<n ; i++ ) {
            vector<bool> visited(n, false);
            answer = max( answer, visit(i, visited, connected) );
        }

        return answer;
    }
};

int main() {

    ios_base::sync_with_stdio(false); 


    return 0;
}

