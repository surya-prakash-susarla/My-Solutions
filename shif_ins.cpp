#include <iostream>
#include <vector>
using namespace std;
void swap(int &a, int &b) {
  int temp = b;
  b = a;
  a = temp;
}
int main() {
  int size;
  cin >> size;
  vector<int> a(size);
  int counter = 0;
  for (int i = 0; i < size; i++) {
    cin >> a[i];
    cout << "waiting for input " << i + 1 << endl;
  }
  cout << "input complete\n";
  for (int i = 0; i < size; i++) {
    int j = i;
    while (j > 0) {
      if (a[j] < a[j - 1]) {
        swap(a[j], a[j - 1]);
        counter++;
      }
      j--;
    }
  }
  cout << counter << endl;
  return 0;
}
