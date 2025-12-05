class Solution {
 public:
  string reverseVowels(string input) {
    set<char> vows = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    auto is_valid = [&](const char c) { return vows.contains(c); };

    int left = -1;
    for (int i = 0; i < input.size(); i++)
      if (is_valid(input[i])) {
        left = i;
        break;
      }

    int right = -1;
    for (int i = input.size() - 1; i > -1; i--)
      if (is_valid(input[i])) {
        right = i;
        break;
      }

    while (left < right) {
      swap(input[left], input[right]);
      left++;
      right--;
      while (left < input.size())
        if (is_valid(input[left])) {
          break;
        } else {
          left++;
        }

      while (right > -1)
        if (is_valid(input[right])) {
          break;
        } else {
          right--;
        }
    }

    return input;
  }
};
