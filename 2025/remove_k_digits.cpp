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
  string trim(string answer) {
    for (int i = 0; i < answer.size(); i++) {
      if (answer[i] != '0')
        return answer.substr(i, answer.size());
    }
    return "0";
  }

  string removeKdigits(string input, int k) {
    stack<char> values;

    if (k >= input.size())
      return "0";

    for (int i = 0; i < input.size(); i++) {
      if (k == 0) {
        string rem = input.substr(i, input.size());
        string temp;
        for (; not values.empty(); values.pop()) {
          temp += values.top();
        }
        reverse(temp.begin(), temp.end());
        string answer = temp + rem;
        answer = trim(answer);
        return answer;
      } else {
        while (not values.empty() and values.top() > input[i] and k) {
          values.pop();
          k--;
        }
        values.push(input[i]);
      }
    }
    string answer;
    while (k) {
      values.pop();
      k--;
    }
    for (; not values.empty(); values.pop())
      answer += values.top();

    reverse(answer.begin(), answer.end());
    answer = trim(answer);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
