#include <iostream>
using namespace std;
int main() {
  long long int x1, x2, y1, y2, xc, yc;
  cin >> x1 >> y1 >> x2 >> y2 >> xc >> yc;
  long long int temp;
  x2 - xc > xc - x1 ? temp = xc - x1 : temp = x2 - xc;
  long long int row = temp * 2;
  y2 - yc > yc - y1 ? temp = yc - y1 : temp = y2 - yc;
  long long int col = temp * 2;
  row += 1;
  col += 1;
  long long int tot_po = row * col;
  long long int maxsq;
  long long int diags = 0;
  row >= col ? maxsq = col : maxsq = row;
  tot_po -= maxsq * maxsq;
  while (maxsq >= 3) {
    long long int sh = ((maxsq * 2) + (maxsq - 2) * 2) / 2;
    diags += sh;
    maxsq -= 1;
  }
  diags += tot_po / 2;
  cout << diags << endl;
  return 0;
}
