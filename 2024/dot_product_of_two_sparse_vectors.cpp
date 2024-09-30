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

class SparseVector {
 public:
  SparseVector(vector<int>& temp) {
    for (int i = 0; i < temp.size(); i++)
      if (temp[i] > 0)
        values[i] = temp[i];
  }

  // Return the dotProduct of two sparse vectors
  int dotProduct(SparseVector& vec) {
    int answer = 0;

    for (auto i : vec.values)
      if (values.contains(i.first))
        answer += (i.second * values[i.first]);

    return answer;
  }

  unordered_map<int, int> values;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
