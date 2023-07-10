#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
  uid_t ruid = getuid();
  uid_t euid = geteuid();
  printf("ruid:%d, euid:%d\n", ruid, euid);
  return 0;
}
