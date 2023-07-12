#include <iostream>
using namespace std;
int main() {
  int n;
  cout << "Enter the number of pages" << endl;
  cin >> n;
  int *page_index = new int[n];
  char *page = new char[n];
  cout << "Enter the pages" << endl;
  for (int i = 0; i < n; i++) {
    cin >> page[i];
    page_index[i] = i + 1;
  }
  cout << "Number of pages in each block is 4" << endl;
  int page_table_size = (n / 4) + (n % 4);
  int *page_table = new int[page_table_size];
  cout << "Enter the page table details" << endl;
  for (int i = 0; i < page_table_size; i++)
    cin >> page_table[i];
  int *frame_table = new int[n];
  cout << "The entered page numbers are:" << endl;
  for (int i = 0; i < n; i++)
    cout << page[i] << endl;
  cout << "The page table details are: " << endl;
  for (int i = 0; i < page_table_size; i++)
    cout << page_table[i] << endl;
  cout << "The frame numbers are as follows:" << endl;
  for (int i = 0; i < n; i++) {
    frame_table[i] =
        (page_table[(page_index[i] - 1) / 4] * 4) + ((page_index[i] - 1) % 4);
    cout << page_index[i] << "\t" << page[i] << "\t" << frame_table[i] << endl;
  }
  return 0;
}
