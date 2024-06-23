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
  typedef pair<int, int> pint;
  typedef priority_queue<pint> max_heap;
  typedef priority_queue<pint, vector<pint>, greater<pint>> min_heap;

  int longestSubarray(vector<int>& input, int limit) {
    // right limits.
    min_heap minvalues;

    // left limits.
    max_heap maxvalues;

    int left = -1;
    int right = 0;

    int answer = 0;

    while (right < input.size()) {
      if (not minvalues.empty() and not maxvalues.empty()) {
        for (; not minvalues.empty() and minvalues.top().second < left;
             minvalues.pop())
          ;
        for (; not maxvalues.empty() and maxvalues.top().second < left;
             maxvalues.pop())
          ;
        if (minvalues.empty() or maxvalues.empty())
          continue;

        int left_limit = maxvalues.top().first;
        int right_limit = minvalues.top().first;

        if (input[right] >= left_limit and input[right] <= right_limit) {
          minvalues.push(make_pair(input[right] + limit, right));
          maxvalues.push(make_pair(max(0, input[right] - limit), right));
          right++;
        } else {
          answer = max(answer, right - left);
          left++;
        }
      } else {
        // one of the queues is empty which indicates that the other queue would
        // also have all invalid pairs so simply discard and start fresh.
        for (; not minvalues.empty(); minvalues.pop())
          ;
        for (; not maxvalues.empty(); maxvalues.pop())
          ;

        left = right;
        right++;
        maxvalues.push(make_pair(max(0, input[left] - limit), left));
        minvalues.push(make_pair(input[left] + limit, left));
        answer = max(answer, 1);
      }
    }

    answer = max(answer, right - left);

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
