class Solution {
 public:
  int firstMissingPositive(vector<int>& values) {
    for (int i = 0; i < values.size();) {
      if (values[i] != i + 1 and values[i] > 0 and
          values[i] <= values.size() and values[values[i] - 1] != values[i]) {
        int cvalue = values[i];
        swap(values[i], values[cvalue - 1]);
      } else {
        i++;
      }
    }

    for (int i = 0; i < values.size(); i++) {
      if (values[i] != i + 1)
        return i + 1;
    }

    return *values.rbegin() + 1;
  }
};
