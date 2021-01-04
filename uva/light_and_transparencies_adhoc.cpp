#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

#define in scanf
#define out printf

// Problem: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=778

typedef long long int llint;
typedef long double ldouble;

typedef std::pair<double, double> pt;

typedef struct _line {
  pt p1;
  pt p2;
  double val;
  _line(const pt a, const pt b, const double temp) : p1(a), p2(b), val(temp) {}
} line;

typedef struct _loc {
  pt p;
  double val;
  bool is_end;
  _loc() = default;
  _loc(pt _p, double _val, bool _is_end = false)
      : p(_p), val(_val), is_end(_is_end) {}
} loc;

bool __compare__(const loc& a, const loc& b) {
  return a.p.first > b.p.first;
}

std::unique_ptr<std::vector<line>> __calc__() {
  llint nl;
  std::cin >> nl;
  if (nl == 0)
    return nullptr;
  std::priority_queue<loc, std::vector<loc>,
                      std::function<bool(const loc& a, const loc& b)>>
      input(__compare__);
  for (llint i = 0; i < nl; i++) {
    pt temp;
    std::cin >> temp.first >> temp.second;
    pt temp2;
    std::cin >> temp2.first >> temp2.second;
    double value;
    std::cin >> value;
    if (temp.first > temp2.first)
      std::swap(temp, temp2);
    input.push(loc(temp, value));
    input.push(loc(temp2, value, true));
  }

  pt last_pt = input.top().p;
  double cm = input.top().val;
  input.pop();

  std::unique_ptr<std::vector<line>> output(new std::vector<line>);

  while (!input.empty()) {
    const loc& temp = input.top();
    output->push_back(line(last_pt, temp.p, cm));
    last_pt = temp.p;
    if (temp.is_end)
      cm /= temp.val;
    else
      cm *= temp.val;
    input.pop();
  }

  // std::cout << "the value of the output is : " << std::endl;
  // for (const line& i : *output) {
  //   std::cout << i.p1.first << " | " << i.p2.first << " => " << i.val
  //             << std::endl;
  // }

  return std::move(output);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  llint t;
  std::cin >> t;
  for (llint i = 0; i < t; i++) {
    std::unique_ptr<std::vector<line>> answer = __calc__();
    if (answer) {
      std::cout << std::setprecision(3) << std::fixed;
      std::cout << answer->size()+2 << "\n-inf"
                << " " << answer->at(0).p1.first << " 1.000\n";
      for (const line& i : *answer) {
        std::cout << i.p1.first << " " << i.p2.first << " " << i.val << "\n";
      }
      std::cout << answer->rbegin()->p2.first << " +inf 1.000\n";
    } else {
      std::cout << "-inf +inf 1.000\n";
    }
    if (i < t - 1)
      std::cout << "\n";
  }
  return 0;
}
