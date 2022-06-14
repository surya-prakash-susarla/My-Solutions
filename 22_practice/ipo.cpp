class Solution {
 public:
  int findMaximizedCapital(int k,
                           int w,
                           vector<int>& profits,
                           vector<int>& capital) {
    typedef long long int llint;
    typedef pair<llint, llint> pint;

    priority_queue<pint, vector<pint>, less<pint>> dsc;
    priority_queue<pint, vector<pint>, greater<pint>> asc;

    llint answer = w;

    for (int i = 0; i < profits.size(); i++)
      asc.push({capital[i], profits[i]});

    while (k) {
      while (!asc.empty() and asc.top().first <= answer) {
        dsc.push({asc.top().second, asc.top().first});
        asc.pop();
      }

      if (not dsc.empty()) {
        answer += dsc.top().first;
        dsc.pop();
      }

      k--;
    }

    return answer;
  }
};
