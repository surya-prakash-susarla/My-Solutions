#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    int paper_index = -1;
    int glass_index = -1;
    int metal_index = -1;

    int pc = 0;
    int gc = 0;
    int mc = 0;

    for (int i = 0; i < garbage.size(); i++) {
      for (char c : garbage[i]) {
        switch (c) {
          case 'P': {
            pc++;
            paper_index = i;
            break;
          }
          case 'M': {
            mc++;
            metal_index = i;
            break;
          }
          case 'G': {
            gc++;
            glass_index = i;
            break;
          }
        }
      }
    }

    int answer = pc + gc + mc;

    for (int i = 0; i < travel.size(); i++) {
      if (i + 1 <= paper_index)
        answer += travel[i];
      if (i + 1 <= metal_index)
        answer += travel[i];
      if (i + 1 <= glass_index)
        answer += travel[i];
    }

    return answer;
  }
};

int main() {
  return 0;
}
