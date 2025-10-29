class Solution {
 public:
  int countValidSelections(vector<int>& input) {
    typedef vector<int> vint;

    vint left(input.size(), 0);
    vint right(input.size(), 0);

    {
      left[0] = input[0];
      for (int i = 1; i < input.size(); i++)
        left[i] = input[i] + left[i - 1];
    }

    {
      right[input.size() - 1] = input[input.size() - 1];
      for (int i = input.size() - 2; i > -1; i--)
        right[i] = input[i] + right[i + 1];
    }

    int answer = 0;

    for (int i = 1; i < input.size() - 1; i++) {
      if (input[i] != 0)
        continue;
      if (left[i - 1] == right[i + 1])
        answer += 2;

      if (abs(left[i - 1] - right[i + 1]) == 1)
        answer += 1;
    }

    if (input.size() == 1) {
      return input[0] == 0 ? 2 : 0;
    }

    if (input[0] == 0) {
      int left = 0;
      int r = right[1];

      if (left == r)
        answer += 2;
      else if (abs(left - r) == 1)
        answer++;
    }

    int n = input.size();
    if (input[n - 1] == 0) {
      int right = 0;
      int l = left[n - 2];

      if (right == l)
        answer += 2;
      else if (abs(l - right) == 1)
        answer++;
    }

    return answer;
  }
};
