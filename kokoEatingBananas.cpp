class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int hours) {
    int min_value = 1, max_value = *max_element(piles.begin(), piles.end()),
        current_value, answer = -1;
    while (min_value <= max_value) {
      current_value = (min_value + max_value) / 2;
      int res = 0;
      for (auto i : piles)
        res += (int)ceil((float)i / current_value);
      if (answer != -1 and current_value >= answer)
        break;
      if (res > hours)
        min_value = current_value + 1;
      else if (hours > res)
        answer = current_value, max_value = current_value - 1;
      else
        answer = current_value, min_value -= 1;
    }
    return answer;
  }
};