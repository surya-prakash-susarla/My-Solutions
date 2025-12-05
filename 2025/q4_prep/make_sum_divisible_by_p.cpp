class Solution {
 public:
  int minSubarray(vector<int>& input, int p) {
    int sum = 0;
    for (int i : input) {
      sum += i;
      sum %= p;
    }

    int req = sum % p;
    if (req == 0)
      return 0;

    unordered_map<int, int> locations;

    int current = 0;
    locations[0] = -1;

    int answer = INT_MAX;

    for (int i = 0; i < input.size(); i++) {
      current = (current + input[i]) % p;

      int need = (current - req + p) % p;

      if (locations.contains(need)) {
        answer = min(answer, i - locations[need]);
      }

      locations[current] = i;
    }

    return answer == input.size() ? -1 : answer;
  }
};
