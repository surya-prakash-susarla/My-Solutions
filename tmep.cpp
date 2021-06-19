#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class node {
public:
  int data;
  node *next;
};

node *head = null;
node *start;

int main() {
  char c = 'y';
  start = head;
  while (c == 'y') {
    if (head == null) {
      head = new node;
      cin >> head->data;
      head->next = null;
    } else {
      node *temp = new node;
      cin >> temp->data;
      head->next = temp;
      head = temp;
    }
    cin >> c;
  }
  cout << "The contents of the ll are " << endl;
  node *temper = start;
  while (temper != null) {
    cout << temper->data << endl;
    temper = temper->next;
  }
  cout << "End" << endl;
  return 0;
}