#include <stdio.h>

int main() {

  char subjects[2][12] = {"Mathematics", "Physics"};
  int grades[2][5];

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 5; j++) {
      printf("Enter %s marks of student %d: ", subjects[i], j+1);
      scanf("%d", &grades[i][j]);
    }
  }

  for (int i = 0; i < 2; i++) {
    int total = 0;

    for (int j = 0; j < 5; j++) {
      total += grades[i][j];
    }

    printf("Average of %s is: %.2f\n", subjects[i], total / 5.0f);
  }

  return 0;
}
