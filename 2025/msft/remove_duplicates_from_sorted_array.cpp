class Solution {
 public:
  int removeDuplicates(vector<int>& input) {
    const int n = input.size();
    int prev = 0;
    int count = 1;
    for (int i = 1; i < input.size(); i++) {
      if (input[i] == input[prev]) {
        input[i] = INT_MAX;
      } else {
        prev = i;
        count++;
      }
    }

    sort(input.begin(), input.end());

    return count;
  }
};
