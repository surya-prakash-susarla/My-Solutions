class Solution {
 public:
  int answer = INT_MIN;

  void __rec__(int index,
               int time,
               int current,
               vector<int>& values,
               map<int, vector<pair<int, int>>>& cons) {
    if (time < 0) {
      return;
    }

    int orig_value = values[index];
    // cout << "at index : " << index << " , current : " << current << " , time
    // : " << time << endl;
    current += values[index];
    // cout << "finalized current : " << current << endl;
    values[index] = 0;

    if (index == 0)
      answer = max(current, answer);

    for (auto i : cons[index]) {
      __rec__(i.first, time - i.second, current, values, cons);
    }

    values[index] = orig_value;
  }

  int maximalPathQuality(vector<int>& values,
                         vector<vector<int>>& edges,
                         int limit) {
    map<int, vector<pair<int, int>>> cons;

    for (auto i : edges) {
      cons[i[0]].push_back(make_pair(i[1], i[2]));
      cons[i[1]].push_back(make_pair(i[0], i[2]));
    }

    // cout << "cons : " << endl;
    // for ( auto i : cons ) {
    //     cout << "node : " << i.first << endl;
    //     cout << "connections : " << endl;
    //     for ( auto j : i.second )   cout << j.first << " , w : " << j.second
    //     << endl;
    // }

    __rec__(0, limit, 0, values, cons);

    return answer;
  }
};
