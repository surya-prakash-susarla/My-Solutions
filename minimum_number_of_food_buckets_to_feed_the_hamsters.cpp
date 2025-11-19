class Solution {
 public:
  int minimumBuckets(string input) {
    int answer = 0;
    int prev_location = -1000;

    for (int i = 0; i < input.size(); i++) {
      if (input[i] == 'H') {
        if (prev_location == i - 1) {
          // there is a bucket already to the left, so the easiest thing to do
          // would be to re-use it. this is then a no-op action cause we're just
          // moving away.
        } else {
          // no bucket, our preference is to place to right, if not then left,
          // if not then fail.
          if (i + 1 < input.size() and input[i + 1] == '.') {
            prev_location = i + 1;
            answer++;
          } else if (i - 1 > -1 and input[i - 1] == '.') {
            prev_location = i - 1;
            answer++;
          } else {
            return -1;
          }
        }

      } else {
        // this is basically no-op.
      }
    }

    return answer;
  }
};
