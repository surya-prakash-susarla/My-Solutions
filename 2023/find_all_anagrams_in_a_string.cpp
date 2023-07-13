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
    vector<int> findAnagrams(string s, string p) {

        if ( s.size() < p.size() )  return {};
        if ( s.size() == p.size() ) {
            sort(s.begin(), s.end());
            sort(p.begin(), p.end());
            if ( s == p )   return {0};
            return {};
        }

       vector<int> answer;

        vector<int> values(26, 0);
        for ( int i=0 ; i<p.size() ; i++ )  values[s[i]-'a']++;

        vector<int> required(26, 0);
        for ( char c: p )   required[c-'a']++;

        for ( int& ref : required ) if ( ref == 0 ) ref = -1;

        auto are_valid = [](const vector<int>& current, const vector<int>& req) -> bool {
            for ( int i=0 ; i<26 ; i++ ) {
                if ( req[i] == -1 ) continue;
                else if ( current[i] != req[i] )    return false;
            }
            return true;
        };

        if ( are_valid ( values, required ) )   answer.push_back(0);

       for(int i=1 ; i<=s.size()-p.size() ; i++) {
            values[s[i-1]-'a']--;
            values[s[i+p.size()-1]-'a']++;
            if ( are_valid(values, required) )  answer.push_back(i);
       }

       return answer;
    }
};

int main() {

    ios_base::sync_with_stdio(false); 


    return 0;
}

