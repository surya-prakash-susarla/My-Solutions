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

    // typedef vector<bool> vbool;
    // typedef vector<vbool> vvbool;
    typedef vector<int> vint;
    typedef vector<vint> vvint;
    typedef pair<int, int> pint;
    typedef pair<pint, int> loc;

    int n;

    vector<loc> generate_locations(loc current, const vvint& visited, const vvint& values ) {
        int i = current.first.first;
        int j = current.first.second;
        int dist = current.second;

        vector<loc> answer;

        auto add_if_valid = [&](int i, int j) -> void {
            if (i<0 or j<0 or i>=n or j>=n or values[i][j] == 1 or visited[i][j] == 2) {
                return;
            }
            else {
                answer.push_back(make_pair(make_pair(i, j), dist+1));
            }
        };

        add_if_valid(i-1, j-1);
        add_if_valid(i-1, j);
        add_if_valid(i-1, j+1);
        add_if_valid(i, j-1);
        add_if_valid(i, j+1);
        add_if_valid(i+1, j-1);
        add_if_valid(i+1, j);
        add_if_valid(i+1, j+1);

        return answer;
    }
    
    int __rec__ ( vector<loc> locations, vvint& visited, const vvint& values ) {
        if ( locations.empty() )    return -1;

        map<pint, int> next;

        for ( const loc& i : locations ) {
            vector<loc> generated = generate_locations(i, visited, values);

            for ( const loc& j : generated ) {
                auto it = next.find(j.first);
                if ( it == next.end() )
                    next[j.first] = j.second;
                else if ( it->second > j.second )
                    it->second = j.second;
            }
        }

        vector<loc> next_locations;
        for ( auto i : next ) {
            int x = i.first.first;
            int y = i.first.second;

            if ( x == n-1 and y == n-1 )    return i.second+1;

            visited[x][y] = 2;
            next_locations.push_back(make_pair(i.first, i.second));
        }


        return  __rec__(next_locations, visited, values);
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& input) {
        n = input.size();

        if ( input[0][0] == 1 or input[n-1][n-1] == 1 )
            return -1;


        if ( n == 1 )   return 1;

        vvint visited ( n , vint ( n , 0 ) );
        return __rec__({make_pair(make_pair(0, 0), 0)}, visited, input);
    }
};

int main() {

    ios_base::sync_with_stdio(false); 


    return 0;
}

