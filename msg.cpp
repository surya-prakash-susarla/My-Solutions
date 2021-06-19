#include <iostream>
using namespace std;
int main() {
  int col;
  cin >> col;
  while (col != 0) {
    string s;
    cin >> s;
    int length = s.length();
    int row = length / col;
    char a[row][col];
    int al = 1, mo = 0;
    for (int i = 0; i < row; i++) {
      if (al == 1) {
        for (int j = 0; j < col; j++)
          a[i][j] = s[mo++];
        al = 2;
      } else if (al = 2) {
        for (int j = col - 1; j >= 0; j--)
          a[i][j] = s[mo++];
        al = 1;
      }
    }
    for (int j = 0; j < col; j++)
      for (int i = 0; i < row; i++)
        cout << a[i][j];
    cout << endl;
    cin >> col;
  }
  return 0;
}
