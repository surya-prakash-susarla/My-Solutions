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

// Problem: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=330

typedef long long int llint;
typedef long double ldouble;

typedef struct {
  llint base;
  llint size;
  llint dim;
  std::vector<std::pair<llint, llint>> bounds;
} array;

// global data
std::map<std::string, array> values;
std::map<std::string, std::vector<llint>> coef;
std::string current_name;
std::vector<llint> current_indices;

void __coeff_calc__() {
  const array& data = values[current_name];
  int cd = data.dim;
  std::vector<llint>& cc = coef[current_name];
  // if (cc.size() != 0) {
  //   std::cout << "SOMETHING WRONG\n";
  // }
  cc.resize(data.dim + 1);
  cc[cd--] = data.size;
  while (cd > 0) {
    cc[cd] = cc[cd + 1] * (data.bounds[cd].second - data.bounds[cd].first + 1);
    cd--;
  }
  cc[0] = data.base;
  for (llint i = 0; i < data.dim; i++) {
    cc[0] -= cc[i + 1] * data.bounds[i].first;
  }
  // std::cout << "COEF FOR -> " << current_name << std::endl;
  // std::cout << "base : " << data.base << std::endl;
  // std::cout << "dim : " << data.dim << std::endl;
  // std::cout << "size : " << data.size << std::endl;
  // std::cout << "bounds : " << std::endl;
  // for ( const std::pair<llint,llint>& i : data.bounds )
  //   std::cout << i.first << " " << i.second << std::endl;
  // std::cout << "calculated valeus :" << std::endl;
  // for ( const llint& i : cc )
  //   std::cout << i << " " ;
  // std::cout << std::endl;
  return;
}

llint __calc__() {
  const std::vector<llint>& co = coef[current_name];
  if (co.size() == 0) {
    __coeff_calc__();
  }
  llint answer = co[0];
  for (llint i = 0; i < current_indices.size(); i++)
    answer += (co[i + 1] * current_indices[i]);
  return answer;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  llint n, r;
  std::cin >> n >> r;
  for (llint i = 0; i < n; i++) {
    array temp;
    std::string name;
    std::cin >> name >> temp.base >> temp.size >> temp.dim;
    temp.bounds.resize(temp.dim);
    for (llint j = 0; j < temp.dim; j++) {
      std::cin >> temp.bounds[j].first >> temp.bounds[j].second;
    }
    values[name] = temp;
  }
  for (llint i = 0; i < r; i++) {
    std::cin >> current_name;
    llint dim = values[current_name].dim;
    std::cout << current_name << "[";
    current_indices.resize(dim);
    for (llint j = 0; j < dim; j++) {
      std::cin >> current_indices[j];
      std::cout << current_indices[j];
      if (j < dim - 1) std::cout << ", ";
    }
    std::cout << "] = " << __calc__() << "\n";
  }
  return 0;
}
