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

// Declarations
node *merge_lists(node *a, node *b);
void partition(node *start, node **first_half, node **second_half);
void printer(node *);

void merge_sort(node *start) {
  cout << "in merge sort starting from " << start->data << endl;
  node *first_half, *second_half;
  partition(start, &first_half, &second_half);
  cout << "returned from partition" << endl;
  merge_sort(first_half);
  merge_sort(second_half);

  start = merge_lists(first_half, second_half);
}

void partition(node *start, node **first_half, node **second_half) {
  node *fast, *slow;
  slow = start;
  fast = start->link;
  if (slow == NULL) {
    *first_half = NULL;
    *second_half = NULL;
    return;
  }
  if (fast == NULL) {
    *first_half = slow;
    *second_half = NULL;
    return;
  }
  while (fast != NULL) {
    fast = fast->link;
    if (fast != NULL) {
      slow = slow->link;
      fast = fast->link;
    }
  }
  *second_half = slow->link;
  slow->link = NULL;
  *first_half = start;
  printer(*first_half);
  printer(*second_half);
  cout << "returning from partition function" << endl;
  return;
}

node *merge_lists(node *a, node *b) {
  node *ml = NULL;
  if (a == NULL)
    return b;
  else if (b == NULL)
    return a;
  else if (a->data <= b->data) {
    ml = a;
    ml->link = merge_lists(a->link, b);
  } else if (a->data > b->data) {
    ml = b;
    ml->link = merge_lists(a, b->link);
  }
  return ml;
}

void printer(node *head) {
  node *iter;
  iter = head;
  while (iter != NULL) {
    cout << iter->data << endl;
    iter = iter->link;
  }
  cout << "printing complete" << endl;
  return;
};

int main() {
  create();
  printer(head);
  merge_sort(head);
  printer(head);
  return 0;
}
