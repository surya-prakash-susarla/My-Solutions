#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename container_type>
void printVector(vector<container_type> input) {
  for (container_type i : input)
    cout << i << " ";
  cout << endl;
  return;
}

template <typename container_type>
void printBasicQueue(queue<container_type> input) {
  while (not input.empty()) {
    cout << input.top() << " ";
    input.pop();
  }
  cout << endl;
  return;
}

template <typename q_container>
void printQueue(q_container input) {
  while (not input.empty()) {
    cout << input.top() << " ";
    input.pop();
  }
  cout << endl;
  return;
}