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
  set<int> valid;
  map<int, int> contents;

  SparseVector(vector<int>& values) {
    for (int i = 0; i < values.size(); i++) {
      if (values[i]) {
        valid.insert(i);
        contents[i] = values[i];
      }
    }
  }

  // Return the dotProduct of two sparse vectors
  int dotProduct(SparseVector& other) {
    vector<int> ind;
    set_intersection(valid.begin(), valid.end(), other.valid.begin(),
                     other.valid.end(), back_inserter(ind));

    int answer = 0;
    for (int i : ind)
      answer += (contents[i] * other.contents[i]);

    return answer;
  }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
