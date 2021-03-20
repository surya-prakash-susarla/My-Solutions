#include <cmath>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

typedef long long int llint;

// Reasoning: After caluclating prefix sum, for every position 'i', it can seen
// that the subarray starting at position x and ending at position i is a
// perfect subarray if the difference is prefixes at location i and location x-1
// is a perfect square. To do this, given prefix at current location i is
// prefix[i], assume all possible squares and see if prefix[i] - square_value =
// diff -> where diff should be one of the previously occuring prefix sum
// values. Then we can simply say that diff + (perfect_square) = current_prefix
// which indicates that elements between diff_index and current_index form a
// perfect subarray.

llint __calc__() {
  llint n;
  std::cin >> n;

  std::unordered_map<llint, llint> store;
  llint answer = 0;
  llint prefix = 0;
  llint current_value = -1;
  llint min_value = 0;

  store[0] = 1;

  for (llint i = 0; i < n; i++) {
    std::cin >> current_value;
    prefix += current_value;

    min_value = std::min(min_value, prefix);

    for (llint j = 0; (prefix - j * j) >= min_value; j++) {
      const llint key = (prefix - j * j);

      const std::unordered_map<llint, llint>::iterator it = store.find(key);
      if (it != store.end())
        answer += it->second;
    }

    store[prefix]++;
  }

  return answer;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  llint t;
  std::cin >> t;

  for (llint i = 1; i <= t; i++) {
    llint answer = __calc__();
    std::cout << "Case #" << i << ": " << answer << std::endl;
  }

  return 0;
}