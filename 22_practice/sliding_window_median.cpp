#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  typedef long long int llint;

  struct cmp {
    bool operator()(llint a, llint b) const { return a > b; }
  };
  typedef multiset<llint, cmp> descending_multiset;
  descending_multiset dsc;

  multiset<llint> asc;

  double __get_median__() {
    if (asc.size() != dsc.size()) {
      return asc.size() > dsc.size() ? *asc.begin() : *dsc.begin();
    }
    return ((double)(*asc.begin() + *dsc.begin())) / 2;
  }

  void __balance__() {
    if (((llint)asc.size() - (llint)dsc.size()) > 1) {
      while (((llint)asc.size() - dsc.size()) > 1) {
        dsc.insert(*asc.begin());
        asc.erase(asc.begin());
      }
    } else if (((llint)dsc.size() - (llint)asc.size()) > 1) {
      while (((llint)dsc.size() - asc.size()) > 1) {
        asc.insert(*dsc.begin());
        dsc.erase(dsc.begin());
      }
    }
  }

  vector<double> medianSlidingWindow(vector<int>& values, int k) {
    vector<double> answer;

    for (llint i = 0; i < k; i++)
      dsc.insert(values[i]);

    // initial setup
    {
      llint mid = k % 2 ? k / 2 + 1 : k / 2;
      if (dsc.size() > 1) {
        for (
            struct {
              descending_multiset::iterator it;
              llint i;
            } s = {dsc.begin(), 0};
            s.i < mid; s.it = next(s.it), s.i++)
          asc.insert(*s.it);
        dsc.erase(dsc.begin(), next(dsc.begin(), mid));
      }
      answer.push_back(__get_median__());
    }

    for (llint i = k; i < values.size(); i++) {
      if (values[i - k] <= *dsc.begin()) {
        dsc.erase(dsc.find(values[i - k]));
      } else {
        asc.erase(asc.find(values[i - k]));
      }

      if (values[i] <= *dsc.begin())
        dsc.insert(values[i]);
      else
        asc.insert(values[i]);

      __balance__();

      answer.push_back(__get_median__());
    }

    return answer;
  }
};
