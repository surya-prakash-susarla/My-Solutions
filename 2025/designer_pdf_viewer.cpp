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

int designerPdfViewer(vector<int> values, string input) {
  int w = input.size();
  int h = 0;

  for (char c : input)
    h = max(h, values[c - 'a']);

  return w * h;
}

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
