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

void element_delete(int pos) {
  int count = 1;
  node *iter, *prev;
  iter = head;
  prev = NULL;
  while (count++ != pos) {
    prev = iter;
    iter = iter->link;
  }
  if (prev == NULL) {
    head = iter->link;
  } else {
    prev->link = iter->link;
  }
  printer();
};

void insert(int pos) {
  int count = 1;
  node *temp, *prev;
  temp = head;
  prev = NULL;
  while (count++ != pos) {
    prev = temp;
    temp = temp->link;
  }
  if (prev == NULL) {
    node *iter = new node;
    int n;
    cout << "enter the number to be inserted" << endl;
    cin >> n;
    iter->data = n;
    iter->link = head;
    head = iter;
  } else {
    node *iter = new node;
    int n;
    cout << "enter the number to be inserted" << endl;
    cin >> n;
    iter->data = n;
    prev->link = iter;
    iter->link = temp;
  }
  printer();
};

void reverse_linked_list() {
  node *next_node;
  next_node = NULL;
  bool complete = false;
  while (next_node != NULL or not complete) {
    node *temp;
    if (next_node == NULL) {
      temp = head->link;
      next_node = temp->link;
      head->link = NULL;
      temp->link = head;
      head = temp;
      complete = true;
    } else {
      temp = next_node;
      next_node = temp->link;
      temp->link = head;
      head = temp;
    }
  }
  printer();
  return;
}

int main() {
  create();
  printer();
  cout << "for delete press 1 , for insert press 2 " << endl;
  int caser;
  cin >> caser;
  int pos;
  switch (caser) {
  case 1:
    cout << "enter the postion to be deleted" << endl;
    cin >> pos;
    element_delete(pos);
    break;
  case 2:
    cout << "enter where the node is to be inserted" << endl;
    cin >> pos;
    insert(pos);
    break;
  }
  cout << "the reverse of the list is " << endl;
  reverse_linked_list();
  return 0;
}
