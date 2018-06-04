#include <stdio.h>

long findFactorial(int number);

int main() {
  printf("Enter number: ");
  int number;
  scanf("%d", &number);
  if (number >= 0) {
    long factorial = findFactorial(number);
    printf("Factorial of %d is %d\n", number, factorial);
  } else {
    printf("Enter a positive number\n");
  }
  return 0;
}

long findFactorial(int number) {
  if (number == 0) {
    return 1;
  } else {
    return number * findFactorial(number-1);
  }
}

/* Test Cases

Test No   Test data       Expected Result                      Actual Result   Pass/Fail
----------------------------------------------------------------------------------------
  1       number = 0      print "Factorial of 0 is 1"          As Expected       Pass
  2       number = 1      print "Factorial of 1 is 1"          As Expected       Pass
  3       number = 4      print "Factorial of 4 is 24"         As Expected       Pass
  4       number = -5     print "Enter a positive number"      As Expected       Pass

*/
