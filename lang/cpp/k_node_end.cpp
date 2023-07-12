#include <iostream>
#define null NULL
using namespace std;

class node {
public:
  int data;
  node *next;
};

void print_data(node *start) {
  node *temp;
  temp = start;
  while (temp != null) {
    cout << temp->data << endl;
    temp = temp->next;
  }
  return;
}

void print_node(int k, node *start) {
  node *temp;
  temp = start;
  node *k_node;
  k_node = temp;

  for (int i = 0; i < k; i++)
    temp = temp->next;
  while (temp != null) {
    k_node = k_node->next;
    temp = temp->next;
  }
  cout << "Kth node from the last is " << endl;
  cout << k_node->data << endl;
  return;
}

int main() {
  node *head, *start;
  head = null;
  char c = 'y';
  while (c == 'y') {
    cout << "Enter data" << endl;
    if (head == null) {
      head = new node;
      cin >> head->data;
      head->next = null;
      start = head;
    } else {
      node *temp = new node;
      cin >> temp->data;
      temp->next = null;
      head->next = temp;
      head = temp;
    }
    cout << "To continue " << endl;
    cin >> c;
  }

  int k;
  cout << "Enter value of k" << endl;
  cin >> k;

  print_node(k, start);

  return 0;
}