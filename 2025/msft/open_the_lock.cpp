class Solution {
 public:
  int openLock(vector<string>& deadends, string target) {
    auto nxt = [&](char c) { return c == '9' ? '0' : char((int)c + 1); };
    auto prev = [&](char c) { return c == '0' ? '9' : char((int)c - 1); };

    queue<string> current;
    current.push("0000");

    unordered_set<string> covered;
    unordered_set<string> exclude(deadends.begin(), deadends.end());

    int answer = -1;
    while (not current.empty()) {
      answer++;
      queue<string> next;

      while (not current.empty()) {
        string temp = current.front();
        current.pop();
        if (covered.contains(temp))
          continue;
        if (exclude.contains(temp))
          continue;
        if (temp == target) {
          return answer;
        }
        covered.insert(temp);

        for (int i = 0; i < 4; i++) {
          string temp2 = temp;
          temp2[i] = nxt(temp[i]);
          next.push(temp2);
          temp2[i] = prev(temp[i]);
          next.push(temp2);
        }
      }

      swap(next, current);
    }

    return -1;
  }
};
