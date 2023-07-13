#include <bits/stdc++.h>

using namespace std;

int __calc__(const vector<int>& input, int target) {
  sort(input.begin(), input.end());

  int answer = 0;
  const int size = input.size();

  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
      int upper_limit = target - input[i] - input[j];
      int trip = 0;
      int ti = j + 1;
      while (input[ti++] < upper_limit)
        trip++;
      answer += trip;
    }
  }

  return answer;
}
