#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

#define in scanf
#define out printf

using namespace std;

// Problem:

typedef long long int llint;
typedef long double ldouble;

enum class dir { none = 0, used, up, left };

void generate(int x,
              int y,
              vector<int>& answer,
              const vector<vector<dir> >& usage,
              const vector<int>& values) {
  if (x == 0 or y == 0)
    return;

  switch (usage[x][y]) {
    case dir::used: {
      answer.push_back(values[x]);
      return generate(x - 1, y - 1, answer, usage, values);
    }
    case dir::up:
      return generate(x - 1, y, answer, usage, values);
    case dir::left:
      return generate(x, y - 1, answer, usage, values);
    default:
      cout << "something is wrong" << endl;
  }

  return;
}

pair<int, vector<int> > __calc__(vector<int> values) {
  vector<int> sorted_values(values.begin(), values.end());
  sort(sorted_values.begin(), sorted_values.end());

  const int minvalue = numeric_limits<int>::min();
  values.insert(values.begin(), minvalue);
  sorted_values.insert(sorted_values.begin(), minvalue);

  cout << "input values : " << endl;
  for (int i : values)
    cout << i << " ";
  cout << endl;

  cout << "sorted values : " << endl;
  for (int i : sorted_values)
    cout << i << " ";
  cout << endl;

  vector<vector<int> > memo(values.size(), vector<int>(values.size(), 0));
  vector<vector<dir> > usage(values.size(),
                             vector<dir>(values.size(), dir::none));

  for (int i = 1; i < values.size(); i++) {
    for (int j = 1; j < values.size(); j++) {
      if (values[i] == sorted_values[j]) {
        memo[i][j] = memo[i - 1][j - 1] + 1;
        usage[i][j] = dir::used;
      } else {
        if (memo[i - 1][j] > memo[i][j - 1]) {
          memo[i][j] = memo[i - 1][j];
          usage[i][j] = dir::up;
        } else {
          memo[i][j] = memo[i][j - 1];
          usage[i][j] = dir::left;
        }
      }
    }
  }

  pair<int, vector<int> > answer;
  answer.first = memo[values.size() - 1][values.size() - 1];

  generate(values.size() - 1, values.size() - 1, answer.second, usage, values);

  reverse(answer.second.begin(), answer.second.end());

  return answer;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; i++)
      cin >> values[i];

    pair<int, vector<int> > answer = __calc__(values);

    cout << "max size : " << answer.first << endl;
    cout << "values in answer : " << endl;
    for (int i : answer.second)
      cout << i << " ";
    cout << endl;

    cout << "DONE" << endl;
    return 0;
  }

  return 0;
}
