class Solution {
 public:
  vector<int> maxScoreIndices(vector<int>& nums) {
    int total_ones = 0;
    for (const int& i : nums)
      if (i == 1)
        total_ones++;

    map<int, vector<int>> counts;
    int fsize = nums.size();

    int ones_seen = 0;
    for (int i = 0; i < nums.size(); i++) {
      int score = (i - ones_seen) + (total_ones - ones_seen);
      counts[score].push_back(i);
      // cout << " at index : " << i << " , score : " << score << endl;
      if (nums[i] == 1)
        ones_seen++;
    }
    counts[fsize - total_ones].push_back(fsize);

    // cout << "at index : " << fsize << " , stored value : " << (fsize -
    // total_ones) << endl;

    vector<int> answer = counts.rbegin()->second;
    return answer;
  }
};