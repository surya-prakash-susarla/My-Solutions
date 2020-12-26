#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

llint mod = 1000000007;

map<llint, llint> prev_values;

pair<llint, llint> findClosest(llint required) {
  if (prev_values.size() == 0 or (prev_values.begin())->first > required)
    return pair<llint, llint>(-1, -1);
  if ((prev_values.begin())->first == required)
    return pair<llint, llint>(required, prev_values.begin()->second);
  return *(--(prev_values.upper_bound(required)));
}

llint calc(llint n) {
  llint limit = 0, exist = 0;
  pair<llint, llint> stored = findClosest(n);
  if (stored != pair<llint, llint>(-1, -1))
    limit = stored.first, exist = stored.second;
  llint answer = 0;
  for (llint i = n; i > limit; i--)
    answer = (answer + i + answer * i) % mod;
  answer = (answer + exist + answer * exist) % mod;
  prev_values.insert(pair<llint, llint>(n, answer));
  return answer;
}

int main() {
  llint t;
  cin >> t;
  while (t-- > 0) {
    llint n;
    cin >> n;
    cout << calc(n);
    if (t + 1 > 1)
      cout << endl;
  }
  return 0;
}