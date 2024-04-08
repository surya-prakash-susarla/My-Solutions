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
  int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> stu;
    queue<int> sand;
    for (int i : students)
      stu.push(i);
    for (int i : sandwiches)
      sand.push(i);

    while (true) {
      queue<int> temp_stu;
      const int og_size = stu.size();
      while (not stu.empty()) {
        if (stu.front() == sand.front()) {
          sand.pop();
        } else {
          temp_stu.push(stu.front());
        }
        stu.pop();
      }
      swap(temp_stu, stu);
      if (stu.size() == og_size)
        break;
    }

    return stu.size();
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
