class Solution {
 public:
  int characterReplacement(string input, int k) {
    map<char, int> counts;

    int left = 0;
    int right = 0;

    auto min_value = [&]() {
      if (counts.size() == 1)
        return k;

      int maxvalue = INT_MIN;
      int sum = 0;

      for (auto i : counts) {
        maxvalue = max(maxvalue, i.second);
        sum += i.second;
      }

      return sum - maxvalue;
    };

    int answer = 0;

    while (right < input.size()) {
      counts[input[right]]++;

      // cout << "contents of counts after update : " << endl;
      // for ( auto i : counts  )    cout << i.first << " , " << i.second <<
      // endl;

      if (counts.size() > 1) {
        while (min_value() > k) {
          counts[input[left]]--;
          // if (counts[input[left]] == 0)
          //     counts.erase(input[left]);
          left++;
        }
      }

      // cout << "finalized contents of counts : " << endl;
      // for ( auto i : counts ) cout << i.first << " , " << i.second << endl;

      answer = max(answer, right - left + 1);

      right++;
    }

    return answer;
  }
};
