#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef long long int llint;

llint n, o, d, x1, x2, a, b, c, m, l;

pair<bool, llint> find_max(llint index, vector<llint> candies, llint sweet,
                           llint odd) {
  if (index == candies.size())
    return make_pair(true, sweet);

  if (sweet > d)
    return make_pair(false, -1);

  pair<bool, llint> included;

  if (candies[index] % 2 == 1) {
    if (odd == 0)
      return make_pair(true, sweet);
    else
      included = find_max(index + 1, candies, sweet + candies[index], odd - 1);
  }

  included = find_max(index + 1, candies, sweet + candies[index], odd);

  if (included.first)
    return make_pair(true, max(included.second, sweet));
  return make_pair(true, sweet);
}

int main() {
  llint t;
  cin >> t;
  while (t-- > 0) {
    cin >> n >> o >> d;
    cin >> x1 >> x2 >> a >> b >> c >> m >> l;

    vector<llint> candies;
    vector<llint> x_values;

    candies.push_back(x1 + l);
    candies.push_back(x2 + l);
    x_values.push_back(x1);
    x_values.push_back(x2);
    for (int i = 2; i < n; i++) {
      llint temp = (a * x_values[i - 1] + b * x_values[i - 2] + c);
      x_values.push_back(temp);
      candies.push_back(temp + l);
    }
    pair<bool, llint> values = find_max(0, candies, 0, o);
    if (values.first)
      cout << values.second << endl;
    else
      cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}