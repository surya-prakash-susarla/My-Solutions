#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int trap(vector<int>& values) {
    int answer = 0;

    set<int> temp;
    vector<int> limits(values.size());

    for (int i = values.size() - 1; i > -1; i--) {
      auto it = temp.lower_bound(values[i]);
      if (it == temp.end()) {
        if (temp.empty()) {
          limits[i] = values[i];
        } else {
          limits[i] = *temp.rbegin();
        }
      } else {
        limits[i] = *it;
      }

      temp.insert(values[i]);
    }

    for (int i = 0; i < values.size();) {
      int highest_limit = min(values[i], limits[i]);
      int j = i + 1;
      while (j < values.size() and values[j] < highest_limit) {
        answer += (highest_limit - values[j]);
        j++;
      }
      i = j;
    }

    return answer;
  }
};

int main() {
  return 0;
}
