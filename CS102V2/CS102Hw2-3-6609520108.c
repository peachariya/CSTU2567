#include <stdio.h>

int main() {
  char choice;
  int num1, num2, num3, smallest, largest;

  printf("Do you want to find smallest or largest number? <S/L> : ");
  scanf(" %c", &choice);

  printf("Enter 3 integers: ");
  scanf("%d %d %d", &num1, &num2, &num3);

  if (choice == 'S' || choice == 's') {
    smallest = num1;
    if (num2 < smallest) smallest = num2;
    if (num3 < smallest) smallest = num3;
    printf("Smallest number: %d\n", smallest);
  } else if (choice == 'L' || choice == 'l') {
    largest = num1;
    if (num2 > largest) largest = num2;
    if (num3 > largest) largest = num3;
    printf("Largest number: %d\n", largest);
  } else {
    printf("Invalid choice!\n");
  }

  return 0;
}