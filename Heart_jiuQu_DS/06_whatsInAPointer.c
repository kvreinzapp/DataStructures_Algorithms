#include <stdio.h>

int main() {
  int num = 5;
  printf("the address of num: %p\n", &num);
  int *pi = &num;
  printf("the result of dereference pi: %d\n", *pi);
  printf("the content of pi: %p\n", pi);
  int **spi = &pi;
  printf("the address of pi: %p\n", spi);
  printf("the content of spi: %p\n", spi);
  printf("the result of dereference spi: %p\n", *spi);
  printf("the result of dereference spi twice: %d\n", **spi);
  printf("the address of spi: %p\n", &spi);
}
