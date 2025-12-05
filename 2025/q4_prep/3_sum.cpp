class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& values) {
    set<vector<int>> temp;

    sort(values.begin(), values.end());

    for (int i = 0; i < values.size(); i++) {
      int j = i + 1;
      int k = values.size() - 1;

      while (j < k) {
        int sum = values[i] + values[j] + values[k];
        if (sum == 0) {
          temp.insert({values[i], values[j], values[k]});
          j++;
          k--;
        } else if (sum < 0) {
          j++;
        } else {
          k--;
        }
      }
    }

    return vector<vector<int>>(temp.begin(), temp.end());
  }
};
