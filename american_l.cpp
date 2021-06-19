
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<char>> grid;

void printer() {

  // for ( int i =0 ; i<n ; i++ ) {
  //	for ( int j=0; j < m ; j++ )
  // cout << grid[i][j] << " " ;
  // cout << endl ;
  //}

  return;
}

int form_l(int x, int y, int length, bool right, bool first_right_step,
           bool bottom_travelled) {

  // cout << " INDICES : =>>>> \t \t" << x << " and " << y << endl ;
  // cout << " DIRECTION : "  << right << endl ;
  // cout << " current length value is " << length << endl ;

  if (x >= n)
    return -1;
  else if (y >= m and not first_right_step) {
    // cout << "returning length as it is " << endl ;
    return length;
  } else if (y >= m and first_right_step)
    return -1;
  // cout << "character at current index is " << grid[x][y] << endl ;

  if (not right and length > 0)
    bottom_travelled = not bottom_travelled;

  if (grid[x][y] == '.')
    length += 1;

  if (grid[x][y] == '*') {
    // cout << "since current value is * , going to other areas " << endl ;
    return max(form_l(x, y + 1, 0, false, false, false),
               form_l(x + 1, y, 0, false, false, false));
  }

  // check if multiple connections are present

  char below_value = '@', right_value = '@';

  if (x + 1 < n and y < m)
    below_value = grid[x + 1][y];
  if (y + 1 < m and x < n)
    right_value = grid[x][y + 1];

  // cout << "the below_value is " << below_value << endl;
  // cout << "the right value is " << right_value << endl;

  if (below_value != '@' and right_value != '@' and
      below_value == right_value) {
    if (below_value == '.') {
      // cout << "RETURNING -1 SINCE THERE ARE . IN BOTH DIRECTIONS " <<endl;
      return -1;
    } else {
      if (right) {
        // cout<<"returning length since right end reached " << endl;
        return length;
      } else {
        return -1;
      }
    }
  }

  int bottom = -1;
  // if ( below_value != '@' and below_value == '.' )
  if (not right)
    bottom = form_l(x + 1, y, length, false, false, false);
  int to_right = -1;
  // if ( right_value != '@' and right_value == '.' )
  if (bottom_travelled) {
    bool temp_first_step = true;
    if (right) {
      // 	cout << "setting first step right to false since already in the
      // same direction  " << x << " " << y << endl ;
      temp_first_step = not temp_first_step;
    }
    to_right =
        form_l(x, y + 1, length, true, temp_first_step, bottom_travelled);
  }

  // cout << "the length of bottom l from " <<x << " " << y << " is " << bottom
  // << endl; cout << "the length of right l from " << x << " " << y << " is "
  // << right_value << endl;

  return max(bottom, to_right);
}

int main() {
  cin >> n >> m;
  // cout<<"n value is " << n << endl;
  // cout<<"m value is " << m << endl;
  for (int i = 0; i < n; i++) {
    vector<char> temp_vector;
    for (int j = 0; j < m; j++) {
      char temp;
      cin >> temp;
      // cout << "CHARACTER INPUT : "<< temp << endl;
      temp_vector.push_back(temp);
    }
    grid.push_back(temp_vector);
  }

  // cout << "the values of the grid are " << endl;

  // printer();

  // cout << "searching for length " << endl ;

  int length = form_l(0, 0, 0, false, false, false);

  if (length == 0 or length == -1)
    cout << "NO";
  else
    cout << "YES" << endl << length;
  return 0;
}
