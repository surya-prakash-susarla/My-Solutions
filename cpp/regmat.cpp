#include <iostream>
using namespace std;
int m, n;
int **a;
int glob_i, glob_j;
void printer() {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)
      cout << a[i][j] << " ";
    cout << endl;
  }
}

bool next_finder() {
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (a[i][j] == 1) {
        glob_i = i;
        glob_j = j;
        return true;
      }
  return false;
}

void path_finder(int i, int j, int &counter) {
  // cout<<"current processing index is "<<i<<" "<<j<<endl;
  if (a[i][j] == 1)
    counter++;
  // cout<<"Current value of counter is "<<counter<<endl;
  a[i][j] = 2;
  if (i - 1 >= 0) {
    if (j - 1 >= 0 && a[i - 1][j - 1] == 1)
      path_finder(i - 1, j - 1, counter);
    if (a[i - 1][j] == 1)
      path_finder(i - 1, j, counter);
    if (j + 1 < n && a[i - 1][j + 1] == 1)
      path_finder(i - 1, j + 1, counter);
  }
  if (j - 1 >= 0 && a[i][j - 1] == 1)
    path_finder(i, j - 1, counter);
  if (j + 1 < n && a[i][j + 1] == 1)
    path_finder(i, j + 1, counter);
  if (i + 1 < m) {
    if (j - 1 >= 0 && a[i + 1][j - 1] == 1)
      path_finder(i + 1, j - 1, counter);
    if (a[i + 1][j] == 1)
      path_finder(i + 1, j, counter);
    if (j + 1 < n && a[i + 1][j + 1] == 1)
      path_finder(i + 1, j + 1, counter);
  }
  return;
}

int main() {
  // cout<<"enter the number of rows and columns"<<endl;
  cin >> m >> n;
  a = new int *[m];
  for (int i = 0; i < m; i++)
    a[i] = new int[n];
  // cout<<"enter the values of the array"<<endl;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];

  // cout<<"\nentered matrix is "<<endl;
  // printer();
  int max = -1;
  while (next_finder()) {
    int zero = 0;
    path_finder(glob_i, glob_j, zero);
    //	cout<<"Returned value is "<<zero<<endl;
    if (zero > max)
      max = zero;
    zero = 0;
    //	cout<<"\n\nProceeding to next region"<<endl;
  }
  cout << max << endl;
  return 0;
}
