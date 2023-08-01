#include <stdio.h>

void display(char arr[][2], int row) {
  for (size_t i = 0; i < row; i++) {
    for (size_t j = 0; j < 2; j++) {
      printf("%d ", arr[i][j]);
    }
  }
}

int main() {
  int arrayOne[4] = {65, 66, 67, 68};
  int arrayTwo[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  printf("For 1d array\n");
  printf("arr is address of first element which is arr[0]: %p\n", arrayOne);
  printf("dereference arr: %d\n", *arrayOne);
  printf("the address of arr[0]: %p\n", &arrayOne[0]);
  printf("the content of arr[0]: %d\n", arrayOne[0]);

  printf("For 2d array\n");
  printf("arr is the address of first element which is arr[0][0]: %p\n",
         arrayTwo);
  printf("arr[0] is the address of first element in first row which is "
         "arr[0][0]: %p\n",
         arrayTwo[0]);
  printf("arr[1] is the address of first elment in second row which is "
         "arr[1][0]: %d\n",
         arrayOne[1]);

  printf("the meaning of &arr[0][0]+1 : %p\n", &arrayTwo[0][0] + 1);
  printf("the meaning of arr[0]+1 : %p\n", arrayTwo[0] + 1);
  printf("the meaning of &arr[0]+1 : %p\n", &arrayTwo[0] + 1);
  printf("the meaning of arr+1 : %p\n", arrayTwo + 1);
}
