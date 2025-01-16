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
  int compress(vector<char>& input) {
    int current_char = input[0];
    int current_count = 1;
    int writer_index = 0;
    int total_count = 1;

    auto write = [](vector<char>& input, int count, int& ind,
                    int& total_count) {
      const string convert = to_string(count);
      for (char c : convert) {
        input[ind++] = c;
        total_count++;
      }
    };

    for (int i = 1; i < input.size(); i++) {
      if (input[i] == current_char) {
        current_count++;
      } else {
        writer_index++;
        if (current_count > 1)
          write(input, current_count, writer_index, total_count);
        input[writer_index] = input[i];
        current_char = input[i];
        current_count = 1;
        total_count++;
      }
    }
    writer_index++;
    if (current_count > 1)
      write(input, current_count, writer_index, total_count);

    return total_count;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
