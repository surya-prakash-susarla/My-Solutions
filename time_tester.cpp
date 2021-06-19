#include <chrono>
#include <iostream>
using namespace std;

int returner(int a) {
  if (a == 1)
    return 1;
  return a - returner(a - 1);
}

int main() {
  auto start = chrono::high_resolution_clock::now();
  cout << returner(200) << endl;
  auto end = chrono::high_resolution_clock::now();
  cout << end - start << endl;
  return 0;
}
