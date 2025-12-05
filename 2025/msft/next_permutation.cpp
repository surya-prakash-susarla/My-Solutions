class Solution {
 public:
  void nextPermutation(vector<int>& input) {
    multiset<int> values;
    values.insert(*input.rbegin());

    for (int i = input.size() - 2; i > -1; i--) {
      values.insert(input[i]);
      if (input[i] < input[i + 1]) {
        auto it2 = values.upper_bound(input[i]);
        input[i] = (*it2);
        values.erase(it2);

        auto it = values.begin();
        for (int j = i + 1; j < input.size(); j++) {
          input[j] = *it;
          it = next(it);
        }

        return;
      }
    }

    sort(input.begin(), input.end());
  }
};
