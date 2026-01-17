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

urn 0;

int vdim = min({first.y - second.b, second.y - second.b, first.y - first.b,
                second.y - first.b});
int hdim = min(first.x - second.a, second.x - second.a);

if (vdim < 0)
  vdim = 0;
if (hdim < 0)
  hdim = 0;

int dim = min(vdim, hdim);
long long answer = (long long)dim * (long long)dim;
// cout << "first : " << endl;
//         // first.print();
//                 // cout << "second : " << endl;
//                         // second.print();
//                                 // cout << "v : " << vdim << " , h : " <<
//                                 hdim << endl;
//                                         // cout << "answer : " << answer <<
//                                         endl;
//                                                 return answer;
//                                                     }
//
//                                                         long long
//                                                         largestSquareArea(vector<vector<int>>&
//                                                         bl,
//                                                         vector<vector<int>>&
//                                                         tr) {
//                                                                 vector<rect>
//                                                                 values;
//                                                                         for (
//                                                                         int
//                                                                         i=0 ;
//                                                                         i<bl.size()
//                                                                         ; i++
//                                                                         )
//                                                                         {class
//                                                                         Solution
//                                                                         {
public:
typedef struct _rect {
  int a;
  int b;
  int x;
  int y;
  _rect(int a, int b, int x, int y) : a(a), b(b), x(x), y(y) {}
  void print() const {
    cout << a << ", " << b << " | " << x << ", " << y << endl;
  }
} rect;

static bool comp(const rect& first, const rect& second) {
  if (first.a != second.a)
    return first.a < second.a;
  if (first.b != second.b)
    return first.b < second.b;
  if (first.x != second.x)
    return first.x < second.x;
  return first.y < second.y;
}

long long overlap(const rect& first, const rect& second) {
  if (second.b > first.y)
    return 0;
  if (second.a > first.x)
    ret rect temp(bl[i][0], bl[i][1], tr[i][0], tr[i][1]);
  values.push_back(temp);
}

sort(values.begin(), values.end(), comp);

// cout << "rectangles : " << endl;
// for ( auto i : values ) {
//     cout << i.a << ", " << i.b << " , top : " << i.x << ", " << i.y << endl;
// }

long long answer = 0;
for (int i = 0; i < values.size(); i++) {
  for (int j = i + 1; j < values.size(); j++) {
    answer = max(answer, overlap(values[i], values[j]));
  }
}

return answer;
}
}
;

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
