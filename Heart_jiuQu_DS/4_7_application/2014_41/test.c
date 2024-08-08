#include <stdio.h>

size_t calculateStringLength(const char *str) {
  size_t length = 0;

  // Iterate through the characters of the string until the null terminator is
  // encountered
  while (str[length] != '\0') {
    length++;
  }

  return length;
}

int main() {
  const char *myString = "Hello";

  // Calculate the length of the string using the function
  size_t length = calculateStringLength(myString);

  printf("Length of the string: %zu\n", length);

  return 0;
}
