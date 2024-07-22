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
  vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    map<int, string> temp;
    for (int i = 0; i < heights.size(); i++)
      temp[heights[i]] = names[i];
    sort(heights.begin(), heights.end(), greater<int>());
    vector<string> answer;
    for (int i : heights)
      answer.push_back(temp[i]);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
