class Solution {
 public:
  int maxProfit(vector<int>& input, int fee) {
    int free = 0;
    int hold = -input[0];

    for (int i = 0; i < input.size(); i++) {
      int tmp = free;
      free = max(free, input[i] + hold - fee);
      hold = max(hold, tmp - input[i]);
    }

    return free;
  }
};
