#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

typedef long long int llint;
typedef long long unsigned int ullint;

using namespace std;

class Solution {
 public:
  vector<int> queryResults(int limit, vector<vector<int>>& input) {
    unordered_map<int, int> mapping;
    unordered_map<int, unordered_set<int>> color_contents;

    vector<int> answer;

    int count = 0;

    for (const vector<int>& i : input) {
      const int ball = i[0];
      const int color = i[1];

      auto existing_mapping = mapping.find(ball);
      if (existing_mapping != mapping.end()) {
        auto ball_list = color_contents.find(existing_mapping->second);
        ball_list->second.erase(ball);
        if (ball_list->second.empty())
          count--;
      }

      auto ball_list = color_contents.find(color);
      if (ball_list != color_contents.end()) {
        ball_list->second.insert(ball);
        if (ball_list->second.size() == 1)
          count++;
      } else {
        color_contents[color].insert(ball);
        count++;
      }

      mapping[ball] = color;

      answer.push_back(count);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
