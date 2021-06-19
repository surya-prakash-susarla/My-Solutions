#include <iostream>
#include <map>
#include <tuple>
#include <vector>
using namespace std;

typedef long long int llint;

char find_winner(llint x, llint y, char parent, string wins_y, string wins_x,
                 map<tuple<llint, llint, char>, char> &memo) {
  if ((x == 0 and wins_x[y] == '0') or (y == 0 and wins_y[x] == '0'))
    return parent;

  char current_player;
  parent == 'a' ? current_player = 'b' : current_player = 'a';
  if (x == 0 || y == 0)
    return current_player;

  map<tuple<llint, llint, char>, char>::iterator it;
  it = memo.find(make_tuple(x, y, current_player));
  if (it != memo.end())
    return it->second;

  char left = find_winner(x - 1, y, current_player, wins_y, wins_x, memo);
  char top = find_winner(x, y - 1, current_player, wins_y, wins_x, memo);

  char return_value;
  if (current_player == 'a') {
    return_value = 'b';
    if (left == 'a' or top == 'a')
      return_value = 'a';
  } else {
    return_value = 'a';
    if (left == 'b' or top == 'b')
      return_value = 'b';
  }
  memo[make_tuple(x, y, current_player)] = return_value;
  return return_value;
}

int main() {
  llint t;
  cin >> t;
  while (t-- > 0) {
    string y_values, x_values;
    cin >> y_values >> x_values;
    llint q;
    cin >> q;
    map<tuple<llint, llint, char>, char> memo;
    while (q-- > 0) {
      llint qx, qy;
      cin >> qx >> qy;
      char find_value = find_winner(qx, qy, 'b', y_values, x_values, memo);
      if (find_value == 'a')
        cout << "1";
      else
        cout << "0";
    }
    if (t > 0)
      cout << endl;
  }
  return 0;
}