#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

typedef long long int llint;
typedef long long unsigned int ullint;

using namespace std;

enum class dir { none = 0, used, up, left };

vector<vector<int> > memo;
vector<vector<dir> > usage;

void get_values(int x, int y, vector<int>& answer, const vector<int>& a) {
  if (x == 0 or y == 0)
    return;
  switch (usage[x][y]) {
    case dir::used: {
      answer.push_back(a[x]);
      return get_values(x - 1, y - 1, answer, a);
    }
    case dir::left: {
      return get_values(x, y - 1, answer, a);
    }
    case dir::up: {
      return get_values(x - 1, y, answer, a);
    }
    default: {
      cout << "ERROR: reached a none value in the usage table" << endl;
      return;
    }
  }
}

pair<int, vector<int> > lcs(vector<int> values_a, vector<int> values_b) {
  values_a.insert(values_a.begin(), -1);
  values_b.insert(values_b.begin(), -1);

  memo = vector<vector<int> >(values_a.size(), vector<int>(values_b.size()));
  usage = vector<vector<dir> >(values_a.size(),
                               vector<dir>(values_b.size(), dir::none));

  for (int i = 0; i < values_a.size(); i++)
    memo[i][0] = 0;
  for (int i = 0; i < values_b.size(); i++)
    memo[0][i] = 0;

  for (int i = 1; i < values_a.size(); i++) {
    for (int j = 1; j < values_b.size(); j++) {
      if (values_a[i] == values_b[j]) {
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

  int first = memo[values_a.size() - 1][values_b.size() - 1];

  vector<int> answer;
  get_values(values_a.size() - 1, values_b.size() - 1, answer, values_a);

  reverse(answer.begin(), answer.end());

  return make_pair(first, answer);
}

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> values_a(n), values_b(n);
  for (int i = 0; i < n; i++)
    cin >> values_a[i];
  for (int i = 0; i < n; i++)
    cin >> values_b[i];

  pair<int, vector<int> > answer = lcs(values_a, values_b);

  cout << "maxsize of the sequence : " << answer.first << endl;
  cout << "values of the sequence : " << endl;
  for (int i : answer.second)
    cout << i << " ";
  cout << endl;

  cout << "DONE" << endl;

  return 0;
}
