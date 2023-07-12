#include <algorithm>
#include <iostream>
#include <string>
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

void swap(node *a, node *b) {
  int temp = a->data;
  a->data = b->data;
  b->data = temp;
  return;
}
void mutate_list(node *start) {
  bool change = true;
  cout << "Enter the limit " << endl;
  int limit;
  cin >> limit;
  cout << "starting the checK" << endl;
  while (change) {

    node *temp;
    temp = start;
    node *low;
    low = null;
    while (temp != null) {
      if (temp->data >= limit) {
        low = temp;
        break;
      }
      temp = temp->next;
    }
    temp = low->next;
    node *high;
    high = null;
    while (temp != null) {
      if (temp->data < limit) {
        high = temp;
        break;
      }
      temp = temp->next;
    }

    if (low != null and high != null) {
      swap(low, high);
    } else
      change = false;
  }
  cout << "completed the swapping process" << endl;
  printer(start);
  return;
}

node *reverse_list(node *start) {
  node *rev;
  rev = null;
  while (start != null) {
    node *temp = new node;
    temp->data = start->data;
    temp->next = null;
    if (rev == null)
      rev = temp;
    else {
      temp->next = rev;
      rev = temp;
    }
    start = start->next;
  }
  return rev;
}

bool check_palindrome(node *start) {
  node *rev;
  rev = reverse_list(start);
  cout << "The reverse of the given list is " << endl;
  printer(rev);
  cout << "End of reverse list " << endl;

  while (start != null and rev != null) {
    cout << "inside the loop statement " << endl;
    if (start->data != rev->data) {
      cout << "returning failure " << start->data << " " << rev->data << endl;
      return false;
    } else {
      start = start->next;
      rev = rev->next;
    }
  }
  cout << " returning true " << endl;
  return true;
}

node *find_common(node *start1, node *start2) {
  int diff = 0;
  bool both = false, first = false, one = false, two = false;
  while (not both) {
    if ((start1 == null and start2 != null) or
        (start1 != null and start2 == null))
      diff += 1;
    if (start1 != null)
      start1 = start1->next;
    if (start2 != null)
      start2 = start2->next;
    if (start1 == null and not first) {
      one = true;
      first = true;
    } else if (start2 == null and not first) {
      two = true;
      first = true;
    }
  }
  if (not one) {
    while (diff-- > 0)
      start1 = start1->next;
  } else if (not two) {
    while (diff-- > 0)
      start2 = start2->next;
  }
  while (start1 == null and start2 != null)
    if (start1->next == start2->next)
      return start1->next;
    else {
      start1 = start1->next;
      start2 = start2->next;
    }
  cout << "no intersection found , possible error in input " << endl;
  return null;
}

int main() {

  /*
  node *head;
  head = input(head);
  printer ( head );

  cout<<"starting the mutation process"<<endl;
  mutate_list(head);
  */                // organising single linked list based on the limit value
  /*
  cout<<"starting the palindrome process"<<endl;
  cout<< (int)check_palindrome(head) <<endl;
  */                // checking if the given single linked list is palindrome

  node *head1;
  head1 = input(head1);
  cout << "head 1 = " << endl;
  printer(head1);
  node *head2;
  head2 = input(head2);
  cout << "head 2 = " << endl;
  printer(head2);
  node *temp = find_common(head1, head2);
  cout << "common node is " << (find_common(head1, head2))->data << endl;

  cout << "EXIT" << endl;
  return 0;
}