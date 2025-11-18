class Solution {
 public:
  bool isOneBitCharacter(vector<int>& input) {
    for (int i = 0; i < input.size(); i++) {
      if (i == input.size() - 1)
        return true;

      if (input[i] == 1) {
        i++;
      } else {
        continue;
      }
    }

    return false;
  }
};
