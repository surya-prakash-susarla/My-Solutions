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
  vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
    unordered_set<int> temp;

    vector<int> answer;

    int counter = 0;

    for (int i = 0; i < a.size(); i++) {
      if (a[i] == b[i]) {
        counter++;
      } else {
        if (temp.contains(a[i]))
          counter++;
        else
          temp.insert(a[i]);
        if (temp.contains(b[i]))
          counter++;
        else
          temp.insert(b[i]);
      }
      answer.push_back(counter);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
