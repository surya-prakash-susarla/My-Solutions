#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  typedef pair<int, int> pint;
  typedef map<int, pint> mpint;
  typedef mpint::iterator mit;

  int deleteAndEarn(vector<int>& nums) {
    mpint values;
    for (int i : nums) {
      values[i].first++;
      values[i].second = -1;
    }

    return __calc__(values.begin(), values);
  }

  int __calc__(mit it, mpint& values) {
    if (it == values.end())
      return 0;

    pint& ref = it->second;

    if (ref.second != -1)
      return ref.second;

    int current_value = it->first * ref.first;

    mit nit = next(it);
    if (nit == values.end()) {
      ref.second = it->first * ref.first;
      return ref.second;
    }

    int next_value = __calc__(nit, values);
    if (nit->first > it->first + 1) {
      ref.second = current_value + next_value;
      return ref.second;
    }

    ref.second = max(next_value, current_value + __calc__(next(nit), values));

    return ref.second;
  }
};