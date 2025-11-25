class Solution {
 public:
  int smallestRepunitDivByK(int k) {
    set<int> seen_remainders;
    int answer = 0;
    int current = 0;
    do {
      current = (current * 10) + 1;
      current %= k;

      if (seen_remainders.contains(current))
        return -1;

      seen_remainders.insert(current);
      answer++;
    } while (current != 0);

    return answer;
  }
};
