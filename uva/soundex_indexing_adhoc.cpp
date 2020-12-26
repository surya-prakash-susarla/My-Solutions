#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <stack>
#include <utility>
#include <vector>

#define in scanf
#define out printf

// Problem: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=680

typedef long long int llint;
typedef long double ldouble;

const llint NONE = '@';

std::map<char, char> con = {{'A', NONE}, {'E', NONE}, {'I', NONE}, {'O', NONE},
                            {'U', NONE}, {'Y', NONE}, {'W', NONE}, {'H', NONE},
                            {'B', '1'},  {'P', '1'},  {'F', '1'},  {'V', '1'},
                            {'C', '2'},  {'S', '2'},  {'K', '2'},  {'G', '2'},
                            {'J', '2'},  {'Q', '2'},  {'X', '2'},  {'Z', '2'},
                            {'D', '3'},  {'T', '3'},  {'L', '4'},  {'M', '5'},
                            {'N', '5'},  {'R', '6'}};

std::string get_code(const std::string& current) {
  std::string answer(4, '0');
  answer[0] = current[0];
  int ci = 1;
  char cc = con[answer[0]], temp;
  for (llint i = 1; i < current.size(); i++) {
    temp = con[current[i]];
    if (temp == NONE || temp == cc) {
      cc = temp;
      continue;
    } else {
      if (ci == 4) {
        return answer;
      } else {
        answer[ci++] = temp;
        cc = temp;
      }
    }
  }
  return answer;
}

inline std::string get_spaces(const int count) {
  return std::string(count, ' ');
}

const std::string prespace = get_spaces(9);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cout << prespace << "NAME" << get_spaces(21) << "SOUNDEX CODE\n";
  std::string current;
  while (std::cin >> current) {
    std::cout << prespace << current << get_spaces(25 - (current.size()))
              << get_code(current) << "\n";
  }
  std::cout << get_spaces(19) << "END OF OUTPUT\n";
  return 0;
}
