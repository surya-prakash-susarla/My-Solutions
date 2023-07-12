#include <iostream>
#include <utility>
#include <vector>
using namespace std;
typedef long long int llint;

// DECLARATIONS
vector<pair<llint, llint>> ladders;
vector<pair<llint, llint>> snakes;
llint sna, lads;

// FUNCTION DECLARATIONS
llint board_game(llint dc, llint cp) {
  cout << "in the function with current position " << cp << endl;
  if (cp + 6 >= 100)
    return dc + 1;
  cout << "proceeding further since current postion is far less than 100"
       << endl;
  for (llint i = 0; i < ladders.size(); i++) {
    if (ladders[i].first == cp)
      return board_game(dc, ladders[i].second);
  }
  for (llint i = 0; i < snakes.size(); i++) {
    if (snakes[i].first == cp)
      return board_game(dc, snakes[i].second);
  }
  vector<llint> vals;
  for (llint i = 1; i < 7; i++) {
    vals.push_back(board_game(dc + 1, cp + i));
  }
  llint mini = vals[0];
  for (llint i = 0; i < vals.size(); i++) {
    if (vals[i] <= mini)
      mini = vals[i];
  }
  return mini;
} // End of function board game

int main() { // DRIVER PROGRAM
  cout << "enter the number of test cases" << endl;
  llint t;
  cin >> t;
  while (t-- > 0) {
    cout << "enter the number of ladders" << endl;
    cin >> lads;
    cout << "enter the pairs of ladders" << endl;
    for (llint i = 0; i < lads; i++) {
      llint a, b;
      cin >> a >> b;
      pair<llint, llint> temp;
      temp.first = a;
      temp.second = b;
      ladders.push_back(temp);
    }
    cout << "enter the number of snakes" << endl;
    cin >> sna;
    cout << "enter the pairs of snakes" << endl;
    for (llint i = 0; i < sna; i++) {
      llint a, b;
      cin >> a >> b;
      pair<llint, llint> temp;
      temp.first = a;
      temp.second = b;
      snakes.push_back(temp);
    }
    cout << "the entered pairs of ladders are " << endl;
    for (llint i = 0; i < ladders.size(); i++)
      cout << ladders[i].first << "\t" << ladders[i].second << endl;
    cout << "the entered pairs of snakes are " << endl;
    for (llint i = 0; i < snakes.size(); i++)
      cout << snakes[i].first << "\t" << snakes[i].second << endl;
    cout << "starting the function call for finding the lowest number of dice "
            "rolls"
         << endl;
    cout << "the lowest number of dice rolls required are " << endl;
    cout << board_game(0, 0);
    if (t > 1)
      cout << endl;
    ladders.clear();
    snakes.clear();
  } // end of while loop
  cout << "program terminated" << endl;
  return 0;
}
