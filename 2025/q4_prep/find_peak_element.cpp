class Solution {
 public:
  int find(int i, int j, const vector<int>& input) {
    int mid = (i + j) / 2;
    if (mid - 1 > -1 and input[mid - 1] > input[mid]) {
      return find(i, mid - 1, input);
    }
    if (mid + 1 < input.size() and input[mid + 1] > input[mid]) {
      return find(mid + 1, j, input);
    }
    return mid;
  }

  int findPeakElement(vector<int>& input) {
    return find(0, input.size() - 1, input);
  }
};
