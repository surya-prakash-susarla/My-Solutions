#include <Windows.h>
#include <iostream>

int main() {
  WIN32_FIND_DATA file;
  HANDLE search_handle = FindFirstFile(L"C:\\*", &file);
  if (search_handle) {
    do {
      std::wcout << file.cFileName << std::endl;
    } while (FindNextFile(search_handle, &file));
    CloseHandle(search_handle);
  }
}
