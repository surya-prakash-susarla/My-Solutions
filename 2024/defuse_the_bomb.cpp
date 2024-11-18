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
  inline int get_prev_index(const int i, const int size, const int k) {
    return (i - k - 1) >= 0 ? i - k - 1 : size + i - k - 1;
  }

  inline int get_next_index(const int i, const int size, const int k) {
    return i + k >= size ? i + k - size : i + k;
  }

  vector<int> decrypt(vector<int>& code, int k) {
    if (k == 0)
      return vector<int>(code.size(), 0);

    vector<int> answer(code.size(), 0);

    if (k < 0) {
      k = -k;
      int init = 0;
      for (int i = 0; i < k; i++) {
        init += code[code.size() - i - 1];
      }
      answer[0] = init;

      for (int i = 1; i < code.size(); i++) {
        init -= code[get_prev_index(i, code.size(), k)];
        init += code[i - 1];
        answer[i] = init;
      }

      return answer;
    }

    if (k > 0) {
      int init = 0;
      for (int i = 0; i < k; i++) {
        init += code[i + 1];
      }
      answer[0] = init;
      for (int i = 1; i < code.size(); i++) {
        init -= code[i];
        init += code[get_next_index(i, code.size(), k)];
        answer[i] = init;
      }
      return answer;
    }

    return {};
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
