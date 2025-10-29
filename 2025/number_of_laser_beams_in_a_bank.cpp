class Solution {
 public:
  int numberOfBeams(vector<string>& input) {
    int answer = 0;
    int prev = 0;

    auto get_count = [](const string& input) -> int {
      int answer = 0;
      for (char c : input)
        if (c == '1')
          answer++;
      return answer;
    };

    for (int i = 0; i < input.size(); i++) {
      int count = get_count(input[i]);
      if (count == 0)
        continue;
      answer += (prev * count);
      prev = count;
    }

    return answer;
  }
};
