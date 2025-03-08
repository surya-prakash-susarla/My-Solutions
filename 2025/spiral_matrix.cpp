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
  vector<vector<int>> input;
  vector<int> answer;

  void print_layer(int i_min, int i_max, int j_min, int j_max) {
    if (i_min == i_max) {
      for (int j = j_min; j <= j_max; j++)
        answer.push_back(input[i_min][j]);
      return;
    }
    if (j_min == j_max) {
      for (int i = i_min; i <= i_max; i++)
        answer.push_back(input[i][j_min]);
      return;
    }

    // left to right
    for (int j = j_min; j < j_max; j++)
      answer.push_back(input[i_min][j]);

    // right to bottom
    for (int i = i_min; i < i_max; i++)
      answer.push_back(input[i][j_max]);

    // bottom to left
    for (int j = j_max; j > j_min; j--)
      answer.push_back(input[i_max][j]);

    // left to top
    for (int i = i_max; i > i_min; i--)
      answer.push_back(input[i][j_min]);
  }

  vector<int> spiralOrder(vector<vector<int>>& input) {
    this->input = input;

    int i_min = 0;
    int i_max = input.size() - 1;
    int j_min = 0;
    int j_max = input[0].size() - 1;

    while (i_min <= i_max and j_min <= j_max) {
      if (i_min == i_max and j_min == j_max) {
        answer.push_back(input[i_min][j_min]);
        break;
      }

      print_layer(i_min, i_max, j_min, j_max);
      i_min++;
      i_max--;
      j_min++;
      j_max--;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
