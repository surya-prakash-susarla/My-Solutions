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

long aVeryBigSum(vector<long> ar) {
  long answer = 0;
  for (long i : ar)
    answer += i;
  return answer;
}

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
