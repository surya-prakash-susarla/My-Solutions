class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& input) {
    stack<int> values;

    for (int i : input) {
      // collision case.
      if (not values.empty() and values.top() > 0 and i < 0) {
        bool inserted = false;
        while (not values.empty()) {
          if (values.top() < 0)
            break;
          if (abs(values.top()) > abs(i)) {
            inserted = true;
            break;
          } else if (abs(values.top()) == abs(i)) {
            values.pop();
            inserted = true;
            break;
          } else {
            values.pop();
          }
        }
        if (not inserted)
          values.push(i);
      } else {
        values.push(i);
      }
    }

    vector<int> answer;
    for (; not values.empty(); values.pop())
      answer.push_back(values.top());

    reverse(answer.begin(), answer.end());

    return answer;
  }
};
