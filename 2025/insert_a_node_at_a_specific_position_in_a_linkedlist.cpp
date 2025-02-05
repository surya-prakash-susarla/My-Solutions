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

typedef SinglyLinkedListNode node;

node* insert(node* current, int current_location, int data) {
  if (current == nullptr) {
    return current_location > 0 ? new node(data) : nullptr;
  }

  if (current_location < 0)
    return current;

  if (current_location == 0) {
    node* temp = new node(data);
    temp->next = insert(current, current_location - 1, data);
    return temp;
  } else {
    current->next = insert(current->next, current_location - 1, data);
    return current;
  }
}

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
