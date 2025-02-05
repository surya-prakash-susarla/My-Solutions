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

bool has_cycle(SinglyLinkedListNode* head) {
  typedef SinglyLinkedListNode node;

  node* slow = head;
  node* fast = head;

  bool first_iter = true;

  if (not head)
    return false;

  while (slow and fast) {
    if (slow == fast && first_iter == false)
      return true;

    first_iter = false;

    slow = slow->next;
    fast = fast->next;
    if (not fast)
      return false;
    fast = fast->next;
  };

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
