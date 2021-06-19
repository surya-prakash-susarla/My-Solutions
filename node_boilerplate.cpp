#include <algorithm>
#include <iostream>
#include <vector>
#define null NULL
using namespace std;

class node {
public:
  int data;
  node *next;
};

node *input(node *head) {
  node *start;
  char c = 'y';
  while (c == 'y') {
    cout << "Enter data" << endl;
    if (head == null) {
      head = new node;
      start = head;
      cin >> head->data;
      head->next = null;
    } else {
      node *temp = new node;
      cin >> temp->data;
      temp->next = null;
      head->next = temp;
      head = temp;
    }
    cout << "to continue press y " << endl;
    cin >> c;
  }
  return start;
}

void printer(node *temp) {
  cout << "The data is " << endl;
  while (temp != null) {
    cout << temp->data << endl;
    temp = temp->next;
  }
  return;
}

int main() {
  node *head;
  head = input(head);
  printer(head);

  return 0;
}