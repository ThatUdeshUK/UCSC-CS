#include <stdio.h>

int fibonacci(int number);

int main() {
  printf("Enter number: ");
  int number;
  scanf("%d", &number);
  if (number >= 0) {
    for (int i = 0; i <= number; i++) {
      printf("%d ", fibonacci(i));
    }
  } else {
    printf("Enter a positive number\n");
  }
  printf("\n");
  return 0;
}

int fibonacci(int number) {
  if (number == 0 || number == 1) {
    return number;
  } else if (number >= 2) {
    return fibonacci(number-1) + fibonacci(number-2);
  }
}

/* Test Cases

Test No   Test data       Expected Result                      Actual Result   Pass/Fail
----------------------------------------------------------------------------------------
  1       number = 3      print "0 1 1 2"                      As Expected       Pass
  2       number = 1      print "0 1"                          As Expected       Pass
  3       number = 0      print "0"                            As Expected       Pass
  4       number = -7     print "Enter a positive number"      As Expected       Pass

*/
