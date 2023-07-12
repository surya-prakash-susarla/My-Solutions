#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
using namespace std;
#define INF numeric_limits<long long int>::max()

class compare {
public:
  int operator()(const pair<long long int, long long int> &a,
                 const pair<long long int, long long int> &b) {
    return a.first > b.first;
  }
};

int main() {
  priority_queue<pair<long long int, long long int>,
                 vector<pair<long long int, long long int>>, compare>
      temp_queue;

  temp_queue.push(make_pair(100, 5));
  temp_queue.push(make_pair(150, 2));
  temp_queue.push(make_pair(12, 1));

  cout << temp_queue.top().first << endl;
  temp_queue.pop();
  cout << temp_queue.top().first << endl;
  temp_queue.pop();
  cout << temp_queue.top().first << endl;
  temp_queue.pop();

  return 0;
}