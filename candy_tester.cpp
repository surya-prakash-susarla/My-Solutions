#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;
typedef long long int llint;
vector<llint> ranks, candies;
llint size;

bool candy_finder(llint n) {
  cout << "currently searching for " << n << endl;
  if (n == size - 1) {
    if (ranks[n - 1] > ranks[n]) {
      if (candies[n - 1] >= 2) {
        candies[n] = 1;
        cout << "return true" << endl;
        return true;
      } else
        return false;
    } else if (ranks[n - 1] < ranks[n]) {
      candies[n] = candies[n - 1] + 1;
      return true;
    } else {
      if (candies[n - 1] >= 2) {
        candies[n] = 1;
        return true;
      } else {
        candies[n] = candies[n - 1] + 1;
        return true;
      }
    }
  }
  if (ranks[n - 1] > ranks[n]) {
    bool found = false;
    for (llint i = 1; not found and i < candies[n - 1]; i++) {
      candies[n] = i;
      found = candy_finder(n + 1);
      cout << "searching for " << n + 1 << " with " << candies[n] << endl;
      cout << "found is " << found << endl;
    }
    if (found) {
      cout << "found something returning true" << endl;
      return true;
    } else
      return false;
  } else if (ranks[n - 1] < ranks[n]) {
    cout << "checking if the previous number has lesser candies" << endl;
    bool found = false;
    for (llint i = candies[n - 1] + 1; not found; i++) {
      candies[n] = i;
      found = candy_finder(n + 1);
    }
    if (found)
      return true;
    return false;
  } else {
    bool found = false;
    for (llint i = 1; not found and i < candies[n - 1]; i++) {
      candies[n] = i;
      found = candy_finder(n + 1);
    }
    if (found) {
      return true;
    } else {
      candies[n] = candies[n - 1];
      found = candy_finder(n + 1);
      if (not found) {
        for (llint i = candies[n - 1] + 1; not found; i++) {
          candies[n] = i;
          found = candy_finder(n + 1);
        }
        return true;
      } else
        return true;
    }
  }
  return false;
}

int main() {
  cout << "enter the size" << endl;
  cin >> size;
  cout << "enter the ranks of the children" << endl;
  for (llint i = 0; i < size; i++) {
    llint temp;
    cin >> temp;
    ranks.push_back(temp);
  }
  cout << "trying to calculate the best path" << endl;
  candies.resize(size);
  bool found = false;
  for (llint i = 1; not found; i++) {
    candies[0] = i;
    found = candy_finder(1);
  }
  cout << "found the best values" << endl;
  cout << "the best values are " << endl;
  llint total = 0;
  for (llint i = 0; i < size; i++) {
    cout << candies[i] << " ";
    total += candies[i];
  }
  cout << "the best sum is " << total << endl;
  cout << total << endl;
  return 0;
}
