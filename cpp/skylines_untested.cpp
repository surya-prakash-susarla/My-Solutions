#include <iostream>
#include <limits>
#include <map>
#include <utility>
#include <vector>

struct building {
  int l;
  int h;
  int r;
};

typedef std::pair<int, int> point;

// globals
int n;
std::vector<building> input;
std::vector<point> output;
std::multimap<int, int> cb;
const int minval = std::numeric_limits<int>::min();

void __print__(const std::multimap<int, int>& cb) {
  for (const point& i : cb) {
    std::cout << i.first << " " << i.second << std::endl;
  }
}

std::multimap<int, int> __delete_marked__(const std::multimap<int, int>& cb) {
  std::multimap<int, int> answer;
  for (const point& i : cb)
    if (i.second != minval)
      answer.insert(i);
  return answer;
}

void __hold__(const int cl) {
  std::cout << "deleting old buildings before l value : " << cl << std::endl;
  std::cout << "values of cb before this iteration : " << std::endl;
  __print__(cb);

  std::multimap<int, int> targets;
  for (auto it = cb.rbegin(); it != cb.rend(); it++) {
    if (it->second <= cl) {
      // handle only bulidings ending before/ at current l value.
      if (targets.empty()) {
        // if empty insert directly
        targets.insert({it->second, it->first});
      } else if (targets.rbegin()->first < it->second) {
        // if non empty then current buildings height must be higher than the
        // farthest expanding building for a shift to happen
        targets.insert({it->second, it->first});
      }
      std::cout << "marking building with height : " << it->first
                << " and r value : " << it->second << " for deletion"
                << std::endl;
      it->second = minval;
    } else {
      // if there is buliding simply overflowing the current limit then every
      // building before it will be smaller due to the multimap and can be
      // deleted safely if it ends before the current building.
      for (auto jt = std::next(it); jt != cb.rend(); jt++) {
        if (jt->second <= cl)
          jt->second = minval;
      }
      break;
    }
  }

  cb = __delete_marked__(cb);

  for (auto it = targets.begin(); it != targets.end(); it++) {
    if (std::next(it) != targets.end()) {
      output.push_back({it->first, std::next(it)->second});
    }
  }

  if (!targets.empty()) {
    std::cout << "targets before pruning : " << std::endl;
    __print__(targets);

    int lh = minval;
    for (auto it = targets.rbegin(); it != targets.rend(); it++) {
      if (it->second > lh) {
        lh = it->second;
      } else {
        it->second = minval;
      }
    }

    targets = __delete_marked__(targets);

    std::cout << "targets after pruning : " << std::endl;
    __print__(targets);

    const point last = *targets.rbegin();
    if (last.first < cl) {
      output.push_back({last.first, 0});
    }
  }

  std::cout << "values of cb after this iteration : " << std::endl;
  __print__(cb);
}

void __calc__() {
  for (const building& i : input) {
    std::cout << "currently processing building : " << i.l << " " << i.h << " "
              << i.r << std::endl;

    std::cout << "previous old buildings : " << std::endl;
    __print__(cb);

    if (cb.empty()) {
      output.push_back({i.l, i.h});
    } else {
      __hold__(i.l);
      if (cb.rbegin()->first < i.h)
        output.push_back({i.l, i.h});
    }
    cb.insert({i.h, i.r});

    std::cout << "cb after handling current building : " << std::endl;
    __print__(cb);
    std::cout << std::endl;

    std::cout << "output after handling the above building : " << std::endl;
    for (const point& i : output)
      std::cout << i.first << " " << i.second << std::endl;
    std::cout << std::endl << std::endl;
  }

  __hold__(std::numeric_limits<int>::max());

  // since this can have multiple buildings starting out at the same level
  // filter them out from the output.
  for (auto it = output.begin(); it != output.end(); it++) {
    if (std::next(it) != output.end()) {
      if (it->first == std::next(it)->first)
        it->first = minval;
    }
  }

  std::vector<point> filtered;
  for (const point i : output)
    if (i.first != minval)
      filtered.push_back(i);

  output = filtered;
}

int main() {
  std::cout << "enter number of buildings: " << std::endl;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    building temp;
    std::cin >> temp.l >> temp.h >> temp.r;
    input.push_back(temp);
  }

  __calc__();

  std::cout << std::endl << std::endl << std::endl;
  std::cout << "FINAL OUTPUT : " << std::endl;
  for (const point& i : output) {
    std::cout << i.first << " " << i.second << std::endl;
  }

  return 0;
}

/*
Sample Input:
8
1 5 11
2 7 6
3 19 13
3 25 14
4 28 24
7 16 12
13 29 23
18 22 19

Sample output:
1 5
2 7
3 25
4 28
13 29
23 28
24 0
*/
