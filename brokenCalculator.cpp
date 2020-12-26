class Solution {
 public:
  int brokenCalc(int input, int target) {
    int moves = 0;
    while (target > input) {
      if (target % 2 == 1) {
        // odd numbered target value
        target += 1;
        moves += 1;
      }
      target = target / 2;
      moves += 1;
    }
    moves += (input - target);
    return moves;
  }
};