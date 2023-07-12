#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef long long int llint;

// ONLY SMALL TEST SET

bool equals(llint x, llint y, llint z) {
  if (x * y == z)
    return true;
  else if (y * z == x)
    return true;
  else if (x * z == y)
    return true;
  return false;
}

llint calc() {
  llint n;
  cin >> n;
  vector<llint> values(n);
  for (llint i = 0; i < n; i++)
    cin >> values[i];
  sort(values.begin(), values.end());
  llint ways = 0;
  for (llint i = values.size() - 1; i > 1; i--)
    for (llint j = i - 1; j > 0; j--)
      for (llint k = j - 1; k > -1; k--)
        if (equals(values[i], values[j], values[k]))
          ways += 1;
  return ways;
}

int main() {
  llint t;
  cin >> t;
  for (llint i = 1; i <= t; i++) {
    llint answer = calc();
    cout << "Case #" << i << ": " << answer << endl;
  }
  return 0;
}
