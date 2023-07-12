#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

void print(stack<pair<int, int>> values) {
  while (not values.empty()) {
    cout << values.top().first << " ";
    values.pop();
  }
  cout << endl;
  return;
}

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& input) {
    stack<pair<int, int>> stack_values;
    vector<int> answer(input.size(), 0);
    int index = 0;
    stack_values.push(make_pair(input[index], index));
    index += 1;
    while (index < input.size()) {
      cout << "current index : " << index << endl;

      if (stack_values.empty())
        stack_values.push(make_pair(input[index], index));
      else {
        cout << "Current value : " << input[index]
             << " , top value of stack : " << stack_values.top().first << endl;

        if (input[index] < stack_values.top().first)
          stack_values.push(make_pair(input[index], index));
        else {
          while (not stack_values.empty()) {
            if (stack_values.top().first < input[index]) {
              answer[stack_values.top().second] =
                  index - stack_values.top().second;
              cout << answer[stack_values.top().second] << endl;
              stack_values.pop();
            } else
              break;
          }
          stack_values.push(make_pair(input[index], index));
          cout << "pushed incoming larger value " << endl;
        }

        cout << "Stack after rearranging : " << endl;
        print(stack_values);
      }
      index += 1;
    }
    return answer;
  }
};

int main() {
  Solution temp;
  int n;
  cin >> n;
  vector<int> input(n);
  for (int i = 0; i < n; i++)
    cin >> input[i];
  auto answer = temp.dailyTemperatures(input);
  for (auto i : answer)
    cout << i << " ";
  cout << endl;
  return 0;
}