class Solution {
 public:
  int maxDistToClosest(vector<int>& input) {
    int answer = 0;

    int prev = -1;

    for (int i = 0; i < input.size(); i++) {
      if (input[i] == 1) {
        if (prev == -1) {
          answer = max(answer, i);
        } else {
          int gap = i - prev - 1;
          if (gap > 0) {
            if (gap % 2) {
              answer = max(answer, (gap / 2) + 1);
            } else {
              answer = max(answer, gap / 2);
            }
          }
        }

        prev = i;
      } else {
        continue;
      }
    }

    if (prev != input.size() - 1) {
      int gap = input.size() - 1 - prev;
      answer = max(answer, gap);
    }

    return answer;
  }
};
