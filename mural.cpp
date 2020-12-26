#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
typedef long long int llint;

llint calc() {
  llint n;
  cin >> n;
  vector<llint> values;
  string input;
  cin >> input;
  for (char c : input)
    values.push_back(c - '0');
  llint len;
  n % 2 == 0 ? len = n / 2 : len = (n / 2) + 1;
  llint max_value = -1, sum_value = 0;
  queue<llint> sum_queue;
  for (llint i = 0; i < len; i++) {
    sum_queue.push(values[i]);
    sum_value += values[i];
  }
  if (sum_value > max_value)
    max_value = sum_value;
  for (llint i = len; i < values.size(); i++) {
    sum_value -= sum_queue.front();
    sum_queue.pop();
    sum_value += values[i];
    sum_queue.push(values[i]);
    if (sum_value > max_value)
      max_value = sum_value;
  }

  return max_value;
}

int main() {
  llint t;
  cin >> t;
  for (int k = 1; k <= t; k++) {
    llint answer = calc();
    cout << "Case #" << k << ": " << answer;
    if (k < t)
      cout << endl;
  }
  return 0;
}