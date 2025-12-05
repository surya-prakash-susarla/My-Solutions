class Solution {
 public:
  int ladderLength(string start, string end, vector<string>& input) {
    unordered_set<string> valid(input.begin(), input.end());

    if (not valid.contains(end))
      return 0;

    unordered_map<int, set<char>> options;
    for (auto i : input) {
      for (int j = 0; j < i.size(); j++)
        options[j].insert(i[j]);
    }

    auto generate = [&](string s, int pos, queue<string>& ref) -> void {
      for (auto c : options[pos]) {
        string temp = s;
        temp[pos] = c;
        ref.push(temp);
      }
    };

    unordered_set<string> covered;
    queue<string> current;
    current.push(start);
    bool initial = true;
    int answer = 0;

    while (not current.empty()) {
      answer++;
      queue<string> next;
      while (not current.empty()) {
        string temp = current.front();

        if (temp == end)
          return answer;

        current.pop();
        if (covered.contains(temp))
          continue;

        if (not initial and not valid.contains(temp))
          continue;

        initial = false;

        covered.insert(temp);
        for (int i = 0; i < start.size(); i++) {
          generate(temp, i, next);
        }
      }

      swap(current, next);
    }

    return 0;
  }
};
