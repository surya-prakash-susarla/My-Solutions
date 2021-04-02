#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

void __input__(std::vector<std::vector<int>>& input) {
  int k = 0;
  for (int i = 0; i < input.size(); i++) {
    for (int j = 0; j < k; j++) {
      std::cin >> input[i][j];
      if (input[i][j] == -1)
        input[i][j] = std::numeric_limits<int>::max();
    }
    k += 1;
  }

  // transpose ;
  for (int j = 0; j < input.size(); j++) {
    for (int i = 0; i < input.size(); i++) {
      input[j][i] = input[i][j];
    }
  }

  return;
}

int __find_index__(const std::vector<int> distances,
                   const std::vector<bool> visits) {
  int answer_ind = -1;
  int answer_val = std::numeric_limits<int>::max();
  for (int i = 0; i < distances.size(); i++) {
    if (!visits[i] && distances[i] < answer_val) {
      answer_val = distances[i];
      answer_ind = i;
    }
  }
  return answer_ind;
}

int __calc__() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> grid(n, std::vector<int>(n));
  __input__(grid);

  std::vector<int> distances(n, std::numeric_limits<int>::max());
  distances[0] = 0;
  std::vector<bool> visits(n, false);

  int current_index = __find_index__(distances, visits);
  while (current_index != -1) {
    visits[current_index] = true;
    for (int j = 0; j < n; j++) {
      if (grid[current_index][j] != std::numeric_limits<int>::max() &&
          !visits[j] &&
          distances[j] > distances[current_index] + grid[current_index][j])
        distances[j] = distances[current_index] + grid[current_index][j];
    }
    current_index = __find_index__(distances, visits);
  }

  return *std::max_element(distances.begin(), distances.end());
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int answer = __calc__();

  std::cout << "Answer : " << answer << std::endl;
  return 0;
}
