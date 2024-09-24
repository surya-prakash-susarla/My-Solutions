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

class Solution {
 public:
  typedef struct _node {
    char c = '@';
    vector<struct _node*> next = vector<struct _node*>(10, nullptr);
  } node;

  node* root;

  void add_node(int num) {
    node* current = root;
    string temp = to_string(num);
    for (int i = 0; i < temp.size(); i++) {
      if (current->next[temp[i] - '0'] == nullptr) {
        node* temp2 = new node();
        temp2->c = temp[i];
        current->next[temp[i] - '0'] = temp2;
        current = temp2;
      } else {
        current = current->next[temp[i] - '0'];
      }
    }
  }

  int find(int num) {
    node* current = root;
    string temp = to_string(num);
    int answer = 0;
    for (int i = 0; i < temp.size(); i++) {
      if (current->next[temp[i] - '0'] != nullptr) {
        answer++;
        current = current->next[temp[i] - '0'];
      } else {
        return answer;
      }
    }
    return answer;
  }

  int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    root = new node();
    for (int i : arr1)
      add_node(i);

    int answer = 0;
    for (int i : arr2)
      answer = max(answer, find(i));

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
