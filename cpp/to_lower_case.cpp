class Solution {
 public:
  string toLowerCase(string input) {
    for (int i = 0; i < input.size(); i++)
      if (input[i] >= 'A' and input[i] <= 'Z')
        input[i] = char((int)input[i] + (int)'a' - (int)'A');
    return input;
  }
};