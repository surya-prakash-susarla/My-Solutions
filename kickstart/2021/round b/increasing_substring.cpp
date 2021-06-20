#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <utility>
#include <map>
#include <stack>
#include <memory>
#include <cmath>
#include <set>
#include <unordered_map>
#include <tuple>

#define in scanf
#define out printf

// Problem: 

typedef long long int llint;
typedef long double ldouble;

std::vector<int> __calc__ () {
    int n; 
    std::cin >> n;
    std::string input;
    std::cin >> input ; 
    std::vector<int> answer ( n , 0 );
    answer[0]=1;
    for ( int i=1 ; i<n ; i++ ){
        answer[i] = input[i] > input[i-1] ? answer[i-1]+1 : 1 ;
    }
    return std::move(answer);
}

int main() {
    int t; 
    std::cin >> t;
    for ( int i=1 ; i<=t ; i++ ){
        std::vector<int> answer = __calc__(); 
        std::cout << "Case #" << i << ": " ; 
        for ( const int& j : answer )   
            std::cout << j << " ";
        std::cout << std::endl;
    }
    return 0;
}
