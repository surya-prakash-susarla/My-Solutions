#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  typedef vector<int> vint;
  typedef vector<vint> vvint;
  typedef vector<string> vstring;

  vector<int> smallestTrimmedNumbers(vector<string>& nums,
                                     vector<vector<int>>& queries) {
    int size = nums.begin()->size();

    vint string_range(nums.size());
    for (int i = 0; i < nums.size(); i++)
      string_range[i] = i;

    vint answer;
    for (vint i : queries) {
      answer.push_back(_get_rank(size - i[1], string_range, i[0], nums));
    }

    return answer;
  }

  int _get_rank(int col_index,
                vint string_range,
                int rank,
                const vstring& input) {
    if (string_range.size() == 1)
      return *string_range.begin();

    if (col_index >= input.begin()->size()) {
      return string_range[rank - 1];
    }

    map<char, vint> values;
    for (int i : string_range) {
      values[input[i][col_index]].push_back(i);
    }

    int temp = 0;
    for (auto it : values) {
      if (temp + it.second.size() < rank) {
        temp += it.second.size();
      } else {
        return _get_rank(col_index + 1, it.second, rank - temp, input);
      }
    }

    return -1;
  }
};
