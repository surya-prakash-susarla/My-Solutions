#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
typedef long long int llint;
llint rows, cols;
int **grid;
bool **covered;
llint largest = -1;

pair<llint, llint> find_index() {
  for (llint i = 0; i < rows; i++)
    for (llint j = 0; j < cols; j++)
      if (grid[i][j] == 1 and not covered[i][j]) {
        return make_pair(i, j);
      }
  return make_pair(-1, -1);
}

bool all_covered() {
  for (llint i = 0; i < rows; i++)
    for (llint j = 0; j < cols; j++)
      if (grid[i][j] == 1 and not covered[i][j])
        return false;
  return true;
}

llint region_counter(pair<llint, llint> start, llint size) {
  llint i = start.first, j = start.second;
  covered[i][j] = true;
  cout << "the current index is " << i << " " << j << endl;
  if (i - 1 >= 0 and grid[i - 1][j] == 1 and not covered[i - 1][j])
    size = region_counter(make_pair(i - 1, j), size + 1);
  if (i + 1 < rows and grid[i + 1][j] == 1 and not covered[i + 1][j])
    size = region_counter(make_pair(i + 1, j), size + 1);
  if (j + 1 < cols and grid[i][j + 1] == 1 and not covered[i][j + 1])
    size = region_counter(make_pair(i, j + 1), size + 1);
  if (j - 1 >= 0 and grid[i][j - 1] == 1 and not covered[i][j - 1])
    size = region_counter(make_pair(i, j - 1), size + 1);
  if (i - 1 >= 0 and j - 1 >= 0 and grid[i - 1][j - 1] == 1 and
      not covered[i - 1][j - 1])
    size = region_counter(make_pair(i - 1, j - 1), size + 1);
  if (i + 1 < rows and j - 1 >= 0 and grid[i + 1][j - 1] == 1 and
      not covered[i + 1][j - 1])
    size = region_counter(make_pair(i + 1, j - 1), size + 1);
  if (i - 1 >= 0 and j + 1 < cols and grid[i - 1][j + 1] == 1 and
      not covered[i - 1][j + 1])
    size = region_counter(make_pair(i - 1, j + 1), size + 1);
  if (i + 1 < rows and j + 1 < cols and grid[i + 1][j + 1] == 1 and
      not covered[i + 1][j + 1])
    size = region_counter(make_pair(i + 1, j + 1), size + 1);
  cout << "the final size at index " << i << " " << j << " is " << size << endl;
  return size;
}

int main(int argc, char const *argv[]) {
  cout << "enter the number of rows and columns " << endl;
  cin >> rows >> cols;
  grid = new int *[rows];
  covered = new bool *[rows];
  for (llint i = 0; i < rows; i++) {
    grid[i] = new int[cols];
    covered[i] = new bool[cols];
    for (llint j = 0; j < cols; j++)
      covered[i][j] = false;
  }
  cout << "enter the values of the grid " << endl;
  for (llint i = 0; i < rows; i++)
    for (llint j = 0; j < cols; j++)
      cin >> grid[i][j];
  cout << "calling the function " << endl;
  while (not all_covered()) {
    llint answer = region_counter(find_index(), 0) + 1;
    if (largest == -1 or (largest != -1 and answer > largest))
      largest = answer;
  }
  cout << "\nthe area of the largest region is " << endl;
  cout << largest << endl;
  return 0;
}
