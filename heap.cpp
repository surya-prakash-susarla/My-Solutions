#include <iostream>
using namespace std;

int size_of_heap = 0;

class node {
public:
  int data;
  node *left, *right;
};

node *root = NULL;

int *arr;

node *create_heap(node *noder) {
  if (noder == NULL)
    noder = new node;
  size_of_heap += 1;
  cout << "enter the data for the node " << endl;
  int d;
  cin >> d;
  noder->data = d;
  noder->left = NULL;
  noder->right = NULL;
  cout << "do you want to create a left node for " << noder->data << endl;
  char c;
  cin >> c;
  if (c == 'y')
    noder->left = create_heap(noder->left);
  cout << "do you want to create a right node for " << noder->data << endl;
  cin >> c;
  if (c == 'y')
    noder->right = create_heap(noder->right);
  cout << "creation complete " << endl;
  return noder;
}

int index_searcher(node *noder) {
  for (int i = 0; i < size_of_heap; i++)
    if (arr[i] == noder->data)
      return i;
  return -1;
}

void arr_converter(node *noder, int *arr, node *parent, bool left = false,
                   bool right = false, bool starter = false) {
  if (starter)
    arr[0] = noder->data;

  else {
    int index = index_searcher(parent);
    if (left)
      arr[2 * index + 1] = noder->data;
    else if (right)
      arr[2 * index + 2] = noder->data;
  }

  if (noder->left != NULL)
    arr_converter(noder->left, arr, noder, true, false, false);
  if (noder->right != NULL)
    arr_converter(noder->right, arr, noder, false, true, false);
  return;
}

void printer_array(int *arr, int size_of_heap) {
  cout << "printing the contents of the array " << endl;
  for (int i = 0; i < size_of_heap; i++)
    cout << arr[i] << endl;
  cout << "printing complete " << endl;
  return;
}

void tree_printer(node *noder) {

  if (noder == NULL)
    return;
  else {
    cout << noder->data << endl;
    tree_printer(noder->left);
    tree_printer(noder->right);
    return;
  }
  return;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
  return;
}

void max_heapify(int i) {
  if (2 * i + 1 < size_of_heap)
    max_heapify(2 * i + 1);
  if (2 * i + 2 < size_of_heap)
    max_heapify(2 * i + 2);
  int largest = i;
  if (2 * i + 1 < size_of_heap and arr[2 * i + 1] > arr[i]) {
    largest = 2 * i + 1;
  } else if (2 * i + 2 < size_of_heap and arr[2 * i + 2] > arr[i]) {
    largest = 2 * i + 2;
  }
  swap(arr[i], arr[largest]);
  if (largest != i)
    max_heapify(largest);
  return;
}

int *heap_sort(int *arr, int *new_arr, int heap_size) {
  new_arr = new int[size_of_heap];
  int counter_index = 0;
  while (size_of_heap > 0) {
    new_arr[counter_index++] = arr[0];
    for (int i = 0; i < heap_size; i++) {
      arr[i] = arr[i + 1];
    }
    size_of_heap -= 1;
    max_heapify(0);
  }
  cout << "the sort is complete " << endl;
  return new_arr;
}

int main() {
  root = create_heap(root);
  cout << "creation of the tree is complete , the contents of the tree are : "
       << endl;
  tree_printer(root);
  arr = new int[size_of_heap];
  cout << "memory allocated to the array " << endl;
  cout << "starting the converter function " << endl;
  arr_converter(root, arr, NULL, false, false, true);
  printer_array(arr, size_of_heap);
  cout << "starting the max heapify procedure " << endl;
  max_heapify(0);
  printer_array(arr, size_of_heap);
  cout << "the size of the heap is " << size_of_heap << endl;
  int *new_arr;
  cout << "starting the heap sort function " << endl;
  int heap_size = size_of_heap;
  new_arr = heap_sort(arr, new_arr, size_of_heap);
  cout << "procedure complete " << endl;
  printer_array(new_arr, heap_size);
  return 0;
}
