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

void __calc__() {
    llint n;
    cin >> n;

    vector<int> values;
    for ( int i=1, j=n/2+1 ; i<=n/2 and j<=n ; i++, j++ ) {
        values.push_back(j);
        values.push_back(i);
    }

    if ( n%2 )  values.push_back(n);

    for ( int i : values ) cout << i << " ";
    cout << endl;

    return;
}

int main() {

    ios_base::sync_with_stdio(false); 

    llint t;
    cin >> t;

    while ( t-- ) {
        __calc__();
    }

    return 0;
}

