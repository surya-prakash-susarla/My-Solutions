class Solution {
 public:
  int minimumLengthEncoding(vector<string>& input) {
    for (string& ref : input)
      reverse(ref.begin(), ref.end());

    sort(input.begin(), input.end());
    reverse(input.begin(), input.end());

    string answer;

    string temp;

    auto contains = [&](const string& a, const string& b) -> bool {
      if (a.size() < b.size())
        return false;

      int s = min(a.size(), b.size());

      for (int i = 0; i < s; i++)
        if (a[i] != b[i])
          return false;

      return true;
    };

    for (auto i : input) {
      if (contains(temp, i))
        continue;

      if (not answer.empty()) {
        answer += "#" + temp;
        temp = i;
      } else {
        answer = temp;
        temp = i;
      }
    }

    if (not answer.empty()) {
      answer += "#" + temp;
    } else {
      answer = temp;
    }

    answer += "#";

    return answer.size();
  }
};
