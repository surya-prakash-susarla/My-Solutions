class Solution {
 public:
  vector<int> twoSum(vector<int>& input, int target) {
    map<int, int> locations;
    for (int i = 0; i < input.size(); i++) {
      locations[input[i]] = i;
    }

    for (int i = 0; i < input.size(); i++) {
      auto it = locations.find(target - input[i]);
      if (it != locations.end() and it->second != i) {
        return {i, it->second};
      }
    }

    return {};
  }
};
