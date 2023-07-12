#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int llint;
#define NULL_VECTOR vector<llint>(0);

llint n, q, l, r;

bool is_valid(llint value) {
  long double sqr = sqrt(value);
  return sqr - ceil(sqr) == 0;
}

vector<llint> find(llint index, vector<llint> values) {
  if (index == values.size())
    NULL_VECTOR;
  vector<llint> solutions;
  if (is_valid(values[index]))
    solutions.push_back(values[index]);

  vector<llint> temp = find(index + 1, values);
  for (llint i : temp) {
    solutions.push_back(i);
    if (is_valid(values[index] & i))
      solutions.push_back(values[index] & i);
  }

  return solutions;
}

int main() {
  llint t;
  cin >> t;
  while (t-- > 0) {
    cin >> n >> q;
    vector<llint> values(n);
    for (llint i = 0; i < n; i++)
      cin >> values[i];
    for (llint i = 0; i < q; i++) {
      cin >> l >> r;
      vector<llint> sub(values.begin() + l, values.begin() + r + 1);
      cout << find_parts(sub).;