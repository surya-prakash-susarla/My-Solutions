#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef long long int llint;

// DEBUG METHODS

void printer(map<pair<llint, llint>, bool> wins) {
  for (map<pair<llint, llint>, bool>::iterator it = wins.begin();
       it != wins.end(); it++) {
    cout << it->first.first << " " << it->first.second << "         "
         << it->second << endl;
  }
  return;
}

// DEBUG METHODS

char alternative(char parent) {
  if (parent == 'a')
    return 'b';
  return 'a';
}

char find_winner(llint x, llint y, char parent,
                 map<pair<llint, llint>, bool> wins) {
  if (wins[make_pair(x, y)]) {
    //	cout << "Correct move by " << parent << endl;
    return parent;
  }
  if (x == 0 || y == 0) {
    //	cout << "False approach by " << parent << endl;
    //	cout << "Returning " << alternative ( parent ) << endl;
    return alternative(parent);
  }

  char current_player = alternative(parent);

  // cout << "Current move of " << current_player << endl;
  // cout << "Index : " << x << " " << y << endl;

  char left = find_winner(x - 1, y, current_player, wins);
  char top = find_winner(x, y - 1, current_player, wins);

  /*
  if ( left == 'a' or top == 'a'  ) return 'a' ;
  return 'b' ;
  */
  // 	 THIS IS THE CORRECT LOGICAL PLAY
  if (current_player == 'a') {
    // logic for 'a'
    char return_value = 'b';
    if (left == 'a' or top == 'a')
      return_value = 'a';

    //	cout << "Returning finally " << return_value << endl;
    return return_value;
  } else {
    // logic for 'b'
    char return_value = 'a';
    if (left == 'b' or top == 'b')
      return_value = 'b';

    //	cout << "Returning finally  " << return_value << endl;
    return return_value;
  }

  // cout << " No return statement " << endl ;
}

int main() {
  llint t;
  cin >> t;
  while (t-- > 0) {

    map<pair<llint, llint>, bool> wins;

    string y_values;
    cin >> y_values;
    for (llint i = 0; i < y_values.size(); i++)
      if (y_values[i] - '0' == 1)
        wins.insert(make_pair(make_pair(0, i + 1), false));
      else
        wins.insert(make_pair(make_pair(0, i + 1), true));
    string x_values;
    cin >> x_values;
    for (llint i = 0; i < x_values.size(); i++)
      if (x_values[i] - '0' == 1)
        wins.insert(make_pair(make_pair(i + 1, 0), false));
      else
        wins.insert(make_pair(make_pair(i + 1, 0), true));

    // cout << "The contents of the winner map is " << endl ;
    // printer ( wins ) ;

    llint q;
    cin >> q;
    while (q-- > 0) {
      llint qx, qy;
      cin >> qx >> qy;

      char find_value = find_winner(qx, qy, 'b', wins);

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