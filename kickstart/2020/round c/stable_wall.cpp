#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <utility>

int row, col;

std::string __calc__() {
  std::cin >> row >> col;

  std::vector<std::vector<char>> input(row, std::vector<char>(col));

  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      std::cin >> input[i][j];

  std::vector<std::vector<std::string>> deps(row,
                                             std::vector<std::string>(col));
  std::map<char, int> dep_counter;
  std::map<char, std::vector<std::pair<int, int>>> locations;

  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++) {
      locations[input[i][j]].push_back({i, j});

      dep_counter[input[i][j]];

      if (i + 1 >= row)
        continue;

      if (input[i][j] != input[i + 1][j]) {
        deps[i + 1][j] += input[i][j];
        dep_counter[input[i][j]]++;
      }
    }

  // debug portion

  // std::cout << "dependency counts are : " << std::endl;
  // for (const std::pair<char, int> &i : dep_counter)
  //   std::cout << "char : " << i.first << " , count : " << i.second << std::endl;

  // std::cout << "dependency locations : " << std::endl;
  // for (int i = 0; i < row; i++)
  //   for (int j = 0; j < col; j++)
  //     std::cout << "location : " << i << "," << j << " , deps => " << deps[i][j]
  //               << std::endl;

  // debug portion

  if (dep_counter.empty()) {
    // no deps at all
    std::set<char> chars;
    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++)
        chars.insert(input[i][j]);

    std::string answer;
    for (const char &i : chars)
      answer += i;

    return answer;
  }

  std::string answer;

  while (!dep_counter.empty()) {

    char current_key = '@';
    for (const std::pair<char, int> &i : dep_counter) {
      if (i.second == 0) {
        current_key = i.first;
        break;
      }
    }

    // std::cout << "dependency counts are : " << std::endl;
    // for (const std::pair<char, int> &i : dep_counter)
    //   std::cout << "char : " << i.first << " , count : " << i.second
    //             << std::endl;

    // std::cout << std::endl << " current key : " << current_key << std::endl;

    if (current_key == '@') {
      return "-1";
    }

    dep_counter.erase(current_key);
    answer += current_key;

    for (const std::pair<int, int> &i : locations[current_key]) {

      // std::cout << "visiting dependent location : " << i.first << " "
      //           << i.second << std::endl;
      // std::cout << "deps there : " << deps[i.first][i.second] << std::endl;

      const std::string &current_deps = deps[i.first][i.second];
      for (const char &c : current_deps)
        dep_counter[c]--;
    }
  }

  return answer;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;

  for (int i = 1; i <= t; i++) {
    const std::string answer = __calc__();
    std::cout << "Case #" << i << ": " << answer << std::endl;
  }

  return 0;
}