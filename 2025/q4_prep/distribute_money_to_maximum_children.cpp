class Solution {
 public:
  int distMoney(int money, int children) {
    auto is_valid = [](int m, int c) -> bool {
      if (m < c)
        return false;
      if (c == 1 and m == 4)
        return false;
      if (m > 0 and c <= 0)
        return false;
      return true;
    };

    int answer = -1;
    for (int i = 0; i <= children; i++) {
      int remaining = children - i;

      if (is_valid(money - 8 * i, remaining)) {
        answer = i;
      } else {
        break;
      }
    }
    return answer;
  }
};
