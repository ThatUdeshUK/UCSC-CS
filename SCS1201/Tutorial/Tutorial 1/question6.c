#include <stdio.h>

int gdc(int n1, int n2);

int main() {
  int num1;
  printf("%s", "Enter number 1: ");
  scanf("%d", &num1);

  int num2;
  printf("%s", "Enter number 2: ");
  scanf("%d", &num2);

  printf("GCD is: %d\n", gdc(num1, num2));

  return 0;
}

int gdc(int n1, int n2) {
  if (n2 == 0) {
    return n1;
  } else {
    return gdc(n2, n1 % n2);
  }
}

/* Test Cases

Test No   Test data                 Expected Result           Actual Result   Pass/Fail
---------------------------------------------------------------------------------------
  1       num1 = 24, num2 = 18      print "GCD is: 6"         As Expected       Pass
  2       num1 = 10, num2 = 0       print "GCD is: 10"        As Expected       Pass
  3       num1 = 0, num2 = 0        print "GCD is: 0"         As Expected       Pass
  4       num1 = 7, num2 = 13       print "GCD is: 1"         As Expected       Pass

*/
