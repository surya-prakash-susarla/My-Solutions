class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& input) {
    typedef vector<int> vint;
    vint left(input.size(), 1);
    vint right(input.size(), 1);

    left[0] = input[0];
    right[input.size() - 1] = input[input.size() - 1];

    for (int i = 1; i < input.size(); i++)
      left[i] = input[i] * left[i - 1];

    for (int i = input.size() - 2; i > -1; i--)
      right[i] = input[i] * right[i + 1];

    vint answer;

    for (int i = 0; i < input.size(); i++) {
      int l = (i - 1 > -1) ? left[i - 1] : 1;
      int r = (i + 1 < input.size()) ? right[i + 1] : 1;
      answer.push_back(l * r);
    }

    return answer;
  }
};
