#include <stdio.h>

int main() {
  int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  printf("is matrix[1] exist?:%d\n", *matrix[1]);
}
