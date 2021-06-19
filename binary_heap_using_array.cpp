#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;

auto print_vector = [](vector<int> values) -> void {
  for (int i : values)
    cout << i << " ";
  cout << endl;
};

void print_heap_vector(vector<int> values, int index) {
  if (values[index] == -1)
    return;
  cout << values[index] << " ";
  if (2 * index + 1 < n)
    print_heap_vector(values, 2 * index + 1);
  if (2 * index + 2 < n)
    print_heap_vector(values, 2 * index + 2);
  return;
}

auto swap_values = [](int &a, int &b) -> void {
  int temp = a;
  a = b;
  b = temp;
  return;
};

void max_heapify(vector<int> &heap, int index) {
  if (index >= n or heap[index] == -1)
    return;
  bool changed = false;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  max_heapify(heap, left);
  max_heapify(heap, right);

  if (left < n and heap[left] != -1 and heap[left] > heap[index]) {
    swap_values(heap[left], heap[index]);
    changed = true;
  }
  if (right < n and heap[right] != -1 and heap[right] > heap[index]) {
    swap_values(heap[right], heap[index]);
    changed = true;
  }

  if (changed)
    max_heapify(heap, index);
  return;
}

void insert(int data, vector<int> &heap) {
  cout << " Inserting " << data << endl;
  cout << " Current values in heap are " << endl;
  print_vector(heap);
  if (heap[0] == -1) {
    heap[0] = data;
    return;
  }
  queue<int> values;
  values.push(0);
  while (not values.empty()) {
    int index = values.front();
    values.pop();
    cout << " INDEX BEING CHECKED :  " << index << endl;
    if (heap[2 * index + 1] == -1) {
      cout << "Inserted at " << 2 * index + 1 << endl;
      heap[2 * index + 1] = data;
      break;
    }
    if (heap[2 * index + 2] == -1) {
      cout << "Inserted at " << 2 * index + 2 << endl;
      heap[2 * index + 2] = data;
      break;
    }
    values.push(2 * index + 1);
    values.push(2 * index + 2);
  }
  cout << "values before heapify are " << endl;
  print_vector(heap);
  max_heapify(heap, 0);
  cout << "the values after heapify are " << endl;
  print_vector(heap);

  cout << endl << endl << "Values in tree model are " << endl;
  print_heap_vector(heap, 0);
  cout << endl << endl;

  cout << endl << endl;
  return;
}

int main() {
  cout << "INPUT SIZE " << endl;
  cin >> n;
  cout << "INPUT " << endl;
  vector<int> input(n);
  for (int i = 0; i < n; i++)
    cin >> input[i];
  cout << " input values are " << endl;
  print_vector(input);
  vector<int> heap(n, -1);

  for (int i : input)
    insert(i, heap);

  cout << "the final values after insertion and heapifying are " << endl;
  print_vector(heap);
  return 0;
}
