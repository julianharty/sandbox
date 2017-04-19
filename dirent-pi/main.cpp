#include <dirent.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  char buf[16];
  int pos = 0;
  // std::nullptr_t  
  dirent *d = reinterpret_cast<struct dirent*>(buf + pos);
  return 0;
}

