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

vector<int> rotLeft(vector<int> a, int d) {
  vector<int> answer;
  for (int i = d; i < a.size(); i++) {
    answer.push_back(a[i]);
  }

  for (int i = 0; i < d; i++) {
    answer.push_back(a[i]);
  }

  return answer;
}

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
