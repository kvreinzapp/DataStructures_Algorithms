#include <stdio.h>

int main() {
  int num = 0;
  int *pi = &num;

  printf("address:%p, address(interger format): %ld, value: %d\n", &num, &num,
         num);
  printf("address:%p, address(interger format): %ld, value: %p\n", &pi, &pi,
         pi);
  printf("%p\n", 4);
}
