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
  vector<string> findAllRecipes(vector<string>& recipes,
                                vector<vector<string>>& ingredients,
                                vector<string>& supplies) {
    unordered_map<string, int> dependencies;
    unordered_map<string, set<string>> dependants;

    for (int i = 0; i < recipes.size(); i++) {
      dependencies[recipes[i]] = ingredients[i].size();
      for (auto j : ingredients[i])
        dependants[j].insert(recipes[i]);
    }

    queue<string> current;
    for (auto i : supplies)
      current.push(i);

    vector<string> answer;

    while (not current.empty()) {
      string top = current.front();
      current.pop();

      if (find(recipes.begin(), recipes.end(), top) != recipes.end()) {
        answer.push_back(top);
      }

      for (auto j : dependants[top]) {
        dependencies[j] -= 1;
        if (dependencies[j] == 0) {
          current.push(j);
        }
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
