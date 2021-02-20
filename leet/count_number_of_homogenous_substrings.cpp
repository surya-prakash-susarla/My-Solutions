#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <stack>
#include <utility>
#include <vector>


// Problem: https://leetcode.com/problems/count-number-of-homogenous-substrings/
// Bi-weekly contest 228

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
 public:
  int countHomogenous(string input) {
    const int mod = 1000000007;
    typedef unsigned long long int ullint;
    ullint answer = input.size() % mod , counter = 1;
    
    auto update_func = [](const ullint& mod, ullint counter, ullint& answer){
        ullint a = counter;
        ullint b = counter-1;
        if ( counter%2 == 0 )   a/=2;
        else    b/=2;
        ullint value = a*b ;
        value %= mod ; 
        answer += value ;
        answer %= mod;
    };
      
    for (int i = 1; i < input.size(); i++) {
      if (input[i] == input[i - 1]) {
        counter++;
      } else {
        update_func ( mod, counter, answer);
          counter =1 ;
      }
    }
    update_func ( mod, counter, answer);
    return answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
