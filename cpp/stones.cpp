#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define b "bob"
#define a "aly"

string play(string player, int stones) {
  cout << "player = " << player << " stones = " << stones << endl;
  if (stones == 1 or stones == 4) {
    cout << "player wins " << player << endl;
    return player;
  }
  if (player == a) {
    string r1 = play(b, stones - 1);
    string r2 = b;
    if (stones > 4)
      r2 = play(b, stones - 4);
    if (r1 == a or r2 == a)
      return a;
    else
      return b;
  } else {
    string r1 = play(a, stones - 1);
    string r2 = a;
    if (stones > 4)
      r2 = play(a, stones - 4);
    if (r1 == b or r2 == b)
      return b;
    else
      return a;
  }
}

int main() {
  int stones;
  cin >> stones;
  if (play(a, stones) == a)
    cout << "yes" << endl;
  else
    cout << "no" << endl;
  return 0;
}