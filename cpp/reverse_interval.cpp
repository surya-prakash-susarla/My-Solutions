#include <iostream>
using namespace std;

class node {
public:
  int data;
  node *link;
};

node *head = NULL;

void create() {
  if (head == NULL) {
    head = new node;
    int n;
    cout << "enter number" << endl;
    cin >> n;
    head->data = n;
    head->link = NULL;
  }
  cout << "do you want to create further" << endl;
  char c;
  cin >> c;
  node *iter;
  iter = head;
  while (c == 'y') {
    node *temp = new node;
    int n;
    cout << "enter number" << endl;
    cin >> n;
    temp->data = n;
    temp->link = NULL;
    iter->link = temp;
    iter = iter->link;
    cout << "do you want to create further" << endl;
    cin >> c;
  }
  cout << "creation complete" << endl;
};

node *beginner;

void printer() {
  node *iter;
  iter = head;
  while (iter != NULL) {
    cout << iter->data << endl;
    iter = iter->link;
  }
  cout << "printing complete" << endl;
  return;
};

node *reverse_forged(node *starter, int interval) {
  node *ender, *c, *d, *t;
  ender = starter;
  c = starter;
  d = NULL;
  t = NULL;
  int count = 0;
  while (count++ < interval and c != NULL) {
    t = c->link;
    c->link = d;
    d = c;
    c = t;
  }
  if (t != NULL)
    ender->link = reverse_forged(t, interval);

  cout << "returning " << d->data << endl;
  return d;
}

node *reverse(node *start, int interval, bool first_time) {
  int count = 0;
  node *prev, *next, *current;
  current = start;
  prev = NULL;
  next = NULL;
  while (count++ < interval and current != NULL) {
    next = current->link;
    current->link = prev;
    prev = current;
    current = next;
  }
  if (first_time)
    beginner = prev;
  if (next != NULL) {
    start->link = reverse(next, interval, false);
  } else
    return prev;
}

int main() {
  create();
  cout << "data is " << endl;
  printer();
  cout << "calling function" << endl;
  // head = reverse(head ,  3 , true);
  // head = beginner;
  head = reverse_forged(head, 3);
  cout << "function call complete" << endl;
  cout << head->data << endl;
  cout << "calling the printer function" << endl;
  printer();
  return 0;
}
