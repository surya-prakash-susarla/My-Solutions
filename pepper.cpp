#include <iostream>
typedef long long int llint;

int main() {
  llint t;
  std::cin >> t;
  while (t-- > 0) {
    llint w, l;
    std::cin >> w >> l;
    llint days = w;
    l = l + w;
    while (l > 6) {
      days = days + 1;
      l = l - 6;
    }
    std::cout << days;
    if (t > 0)
      std::cout << std::endl;
  }
  return 0;
}
