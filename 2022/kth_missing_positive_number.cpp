class Soluton {
 public:
  int findKthPositive(vector<int>& values, int k) {
    int orig = k;

    k -= (values[0] - 1);
    if (k <= 0)
      return orig;

    for (int i = 1; i < values.size(); i++) {
      orig = k;
      k -= (values[i] - values[i - 1] - 1);
      if (k <= 0)
        return values[i - 1] + orig;
    }

    return *values.rbegin() + k;
  }
};
