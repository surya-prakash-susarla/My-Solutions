#include <cmath>
#include <iostream>
using namespace std;

int main() {
  long long int n;
  cin >> n;
  long long int val = 1;
  for (int i = 0; i < n; i++) {
    long long int temp;
    cin >> temp;
    val *= temp;
  }
  val *= 4;
  cout << floor(val / 1024) << endl;
  return 0;
}
