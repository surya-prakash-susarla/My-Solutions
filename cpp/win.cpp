#include <Windows.h>
#include <iostream>
using namespace std;
int main() {
  WIN32_FIND_DATA file;
  HANDLE search = FindFirstFile(L"C:\\*", &file);
  if (search) {
    do {
      wcout << file.cFileName << endl;
    } while (FindNextFile(search, &file));
    CloseHandle(search);
  }
  return 0;
}
