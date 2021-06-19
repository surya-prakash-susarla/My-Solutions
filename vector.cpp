#include <iostream>
using namespace std;
int main() {
  int arr[5];
  cout << "Enter 5 numbers" << endl;
  for (int &i : arr) {
    cin >> i;
    i += 2;
  }
  cout << "The output is " << endl;
  for (int i : arr)
    cout << i << endl;
  return 0;
}
