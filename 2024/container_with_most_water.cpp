#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

typedef long long int llint;
typedef long long unsigned int ullint;

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& values) {
        int left = 0;
        int right = values.size()-1;

        int answer = INT_MIN;

        while ( left < right ) {
            int current = min(values[left], values[right]) * (right - left);
            answer = max(answer, current);

            if ( values[left] < values[right] )
                left++;
            else
                right--;
        }

        return answer;
    }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
