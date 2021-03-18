#include <iostream>
#include <limits>
#include <vector>

using namespace std;
typedef long long int llint;

llint __calc__() {
  llint n;
  cin >> n;

  llint first_value, previous_value, current_value;
  cin >> first_value >> previous_value;

  llint diff = previous_value - first_value;
  llint answer = 1, current_count = 1;

  for (llint i = 2; i < n; i++) {
    cin >> current_value;
    if ((current_value - previous_value) == diff) {
      current_count++;
    } else {
      current_count = 1;
      diff = (current_value - previous_value);
    }
    answer = max(answer, current_count);
    previous_value = current_value;
  }

  return answer + 1;
}

int main() {
  llint t;
  cin >> t;
  for (llint i = 1; i <= t; i++) {
    llint answer = __calc__();

    cout << "Case #" << i << ": " << answer;
    if (i < t)
      cout << endl;
  }
}