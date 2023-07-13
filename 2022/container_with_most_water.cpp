#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& values) {
    int answer = 0;
    int left = 0;
    int right = values.size() - 1;

    while (left < right) {
      answer = max(answer, (right - left) * min(values[left], values[right]));
      if (values[left] > values[right])
        right--;
      else
        left++;
    }

    return answer;
  }
};

int main() {
  return 0;
}
