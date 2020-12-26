#include <iostream>
#include <vector>

using namespace std;
typedef long long int llint;

llint __calc__() {
  llint n;
  cin >> n;
  vector<llint> values(n, 0);
  for (llint i = 0; i < n; i++)
    cin >> values[i];
  llint answer = 0;
  llint current_max = -1;
  for (llint i = 0; i < n; i++) {
    if (values[i] > current_max) {
      current_max = values[i];
      if (i + 1 < n) {
        if (values[i + 1] < values[i]) {
          answer += 1;
        }
      } else {
        answer += 1;
      }
    }
  }
  return answer;
}

int main() {
  llint t;
  cin >> t;
  for (llint i = 1; i <= t; i++) {
    cout << "Case #" << i << ": " << __calc__();
    if (i < t)
      cout << endl;
  }
  return 0;
}