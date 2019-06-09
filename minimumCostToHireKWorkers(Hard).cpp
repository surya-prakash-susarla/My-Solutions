#include  <bits/stdc++.h>
using namespace std;
typedef long double ld ;

// idea : calculate the ratio of all the workers using wage/quality. Store the wages in ascending order. For each worker in the map
//        take the lowest k-1 workers with ratio less than the current worker. Store the lowest K workers in a multiset since the quality
//        values may be repeated. Lowest such value is the answer.

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        multimap<ld,int> ratioValues ;
        for ( int i=0 ; i<quality.size() ; i++ )
            ratioValues.insert({(ld)wage[i]/quality[i],quality[i]});
        multiset<int> qualityValues;
        
        multimap<ld,int>::iterator it = ratioValues.begin() ;
        pair<ld,int> currentValue ;
        int qualitySum = 0 ;

        while ( k-- > 0 ) {
            currentValue = *it ;
            qualitySum += currentValue.second ;
            qualityValues.insert ( currentValue.second );
            it++;
        }
        ld answer = qualitySum * currentValue.first ;
        
        while ( it != ratioValues.end() ) {
            // if maximum value in set is lower than the quality value 
            // then there is no advantage in replacing them since the ratio is already higher 
            currentValue = *it ;
            if (currentValue.second < *--qualityValues.end()){
                qualitySum = qualitySum - *--qualityValues.end() + currentValue.second ;
                qualityValues.erase ( --qualityValues.end() );
                qualityValues.insert ( currentValue.second );
                answer = min ( answer , qualitySum * currentValue.first );
            }
            it++;
        }
        
        return answer;
    }
};

int main() {
    int n ; 
    cin >> n ;
    vector<int> q ( n ) , w ( n );
    for ( int i=0 ; i<n ; i++ ) cin >> q[i] ;
    for ( int i=0 ; i<n ; i++ ) cin >> w[i] ;
    int k ;
    cin >> k ;
    cout << "input complete" << endl ;
    Solution temp ;
    double answer = temp.mincostToHireWorkers ( q , w , k ) ; 
    cout << "Answer : " << answer << endl ;
    return 0;
}