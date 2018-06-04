#include <stdio.h>

int sum(int number);

int main() {
  printf("Enter number: ");
  int number;
  scanf("%i", &number);
  if (number >= 0) {
    printf("Sum of natural numbers upto %d is %d\n", number, sum(number));
  } else {
    printf("Enter a natural number\n");
  }
  return 0;
}

int sum(int number) {
  if (number == 1) {
    return 1;
  } else if (number > 1) {
    return number + sum(number-1);
  }
}

/* Test Cases

Test No   Test data       Expected Result                                    Actual Result   Pass/Fail
------------------------------------------------------------------------------------------------------
  1       number = 4      print "Sum of natural numbers upto 4 is 10"        As Expected       Pass
  2       number = 1      print "Sum of natural numbers upto 1 is 1"         As Expected       Pass
  3       number = 0      print "Sum of natural numbers upto 0 is 0"         As Expected       Pass
  4       number = -3     print "Enter a naural number"                      As Expected       Pass

*/
