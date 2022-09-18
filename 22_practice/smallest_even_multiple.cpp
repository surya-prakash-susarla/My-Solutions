#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int smallestEvenMultiple(int n) {
    for (int i = 1; i < numeric_limits<int>::max(); i++)
      if ((n * i) % 2 == 0)
        return (n * i);

    return n;
  }
};

int main() {
  return 0;
}
