#include <stdio.h>

void findPattern(int number);

int main() {
  printf("Enter number: ");
  int number;
  scanf("%d", &number);
  if (number > 0) {
    findPattern(number);
  } else {
    printf("Enter a positive number\n");
  }
  printf("\n");
  return 0;
}

void findPattern(int number) {
  if (number == 1) {
    printf("%d", 1);
  } else {
    findPattern(number-1);
    printf("%d", number);
    findPattern(number-1);
  }
}

/* Test Cases

Test No   Test data       Expected Result                     Actual Result   Pass/Fail
---------------------------------------------------------------------------------------
  1       number = 4      print "121312141213121"             As Expected       Pass
  2       number = 1      print "1"                           As Expected       Pass
  3       number = 0      print "Enter a positive number"     As Expected       Pass
  4       number = -6     print "Enter a positive number"     As Expected       Pass

*/
