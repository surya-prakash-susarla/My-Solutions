#include <bits/stdc++.h>

using namespace std;

/* Tests:
[1,2,1]
[0,1,2,2]
[1,2,3,2,2]
[0,0,0,0,0,0,0]
[3,3,3,1,2,1,1,2,3,3,4]
[0]
[0,1,2,2,2,2,1,2]
[0,1,6,6,4,4,6]
[1,0,1,4,1,4,1,2,3]
*/

class Solution {
 public:
  int totalFruit(vector<int>& fruits) {
    typedef struct {
      int type;
      int first;
      int last;
    } finfo;

    auto print_fruit = [](const finfo& fruit) {
      cout << "type : " << fruit.type << endl;
      cout << "first : " << fruit.first << endl;
      cout << "last : " << fruit.last << endl;
      return;
    };

    finfo first;
    finfo second;

    first.type = fruits[0];
    first.first = 0;
    first.last = 0;

    int i = 0;
    while (++i < fruits.size() and fruits[i] == first.type)
      ;

    if (i == fruits.size())
      return fruits.size();

    first.last = i - 1;
    second.type = fruits[i];
    second.first = i;
    second.last = i;

    int answer = 0;

    // cout << "initial fruit a : " << endl;
    // print_fruit(first);
    // cout << "initial fruit b : " << endl;
    // print_fruit(second);
    // cout << endl;

    for (int i = second.last + 1; i < fruits.size(); i++) {
      if (fruits[i] == first.type)
        first.last = i;
      else if (fruits[i] == second.type)
        second.last = i;
      else {
        answer = max(answer, i - first.first);
        finfo rfruit;
        if (first.last > second.last) {
          rfruit.type = first.type;
          rfruit.first = min(second.last + 1, first.last);
        } else {
          rfruit.type = second.type;
          rfruit.first = min(first.last + 1, second.last);
        }
        rfruit.last = i - 1;

        first = rfruit;
        second.type = fruits[i];
        second.first = i;
        second.last = i;

        // cout << "updated fruit a : " << endl;
        // print_fruit(first);
        // cout << "updated fruit b : " << endl;
        // print_fruit(second);
        // cout << "updated answer : " << answer << endl;
        // cout << endl;
      }
    }

    answer = max(answer, (int)fruits.size() - first.first);
    // cout << "final answer : " << answer << endl;
    return answer;
  }
};