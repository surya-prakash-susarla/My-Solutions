#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int lowest = -1, highest = -1, lch = 0, hch = 0;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    if (i == 0) {
      lowest = temp;
      highest = temp;
    } else {
      if (temp > highest) {
        highest = temp;
        hch++;
      } else if (temp < lowest) {
        lowest = temp;
        lch++;
      }
    }
  }
  cout << hch << " " << lch << endl;
  return 0;
}
