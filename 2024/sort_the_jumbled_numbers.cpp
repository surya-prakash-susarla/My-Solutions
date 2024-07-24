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
  int convert(int input, const vector<int>& mapping) {
    if (input == 0)
      return mapping[input];
    int answer = 0;
    int i = 0;
    while (input) {
      int rem = (input % 10);
      answer = (mapping[rem] * pow(10, i)) + answer;
      i++;
      input /= 10;
    }
    return answer;
  }

  vector<int> sortJumbled(vector<int>& mapping, vector<int>& input) {
    vector<pair<int, int>> answer;
    for (int i = 0; i < input.size(); i++)
      answer.push_back(make_pair(convert(input[i], mapping), i));

    sort(answer.begin(), answer.end(),
         [](const pair<int, int>& a, const pair<int, int>& b) {
           if (a.first == b.first)
             return a.second < b.second;
           return a.first < b.first;
         });

    vector<int> final_answer;
    for (const pair<int, int>& i : answer)
      final_answer.push_back(input[i.second]);

    return final_answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
