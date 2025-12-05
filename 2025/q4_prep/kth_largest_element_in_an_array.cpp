class Solution {
 public:
  int findKthLargest(vector<int>& input, int k) {
    priority_queue<int, vector<int>, greater<int>> values;

    for (int i : input) {
      values.push(i);

      while (values.size() > k)
        values.pop();
    }

    return values.top();
  }
};
