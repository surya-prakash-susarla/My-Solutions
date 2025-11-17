class Solution {
 public:
  bool kLengthApart(vector<int>& input, int k) {
    // magic number
    int prev = -1000006;

    for (int i = 0; i < input.size(); i++) {
      if (input[i] == 1) {
        int dist = i - prev;
        if (dist < k + 1)
          return false;
        prev = i;
      }
    }

    return true;
  }
};
