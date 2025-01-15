#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

typedef long long int llint;
typedef long long unsigned int ullint;

using namespace std;

class Solution {
 public:
  int minimizeXor(int _target, int _source) {
    bitset<32> target(_target);
    bitset<32> source(_source);

    bitset<32> answer_bits;

    int counter = source.count();

    for (int i = 31; i > -1 && counter > 0; i--) {
      if (target[i] == 1) {
        answer_bits.set(i);
        counter--;
      }
    }

    for (int i = 0; i < 32 and counter > 0; i++) {
      if (answer_bits[i] != 1) {
        counter--;
        answer_bits.set(i);
      }
    }

    return int(answer_bits.to_ulong());
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
