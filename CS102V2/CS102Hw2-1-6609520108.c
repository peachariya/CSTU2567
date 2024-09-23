#include <stdio.h>

int main() {
  float motherHeight, fatherHeight, averageHeight, minHeight, maxHeight;

  printf("Enter the height of the mother (centimeters): ");
  scanf("%f", &motherHeight);

  printf("Enter the height of the father (centimeters): ");
  scanf("%f", &fatherHeight);

  averageHeight = (motherHeight + fatherHeight) / 2;
  minHeight = averageHeight - 13.5;
  maxHeight = averageHeight + 13.5;

  printf("The possible height of the child is between %.2f to %.2f centimeters.\n", minHeight, maxHeight);

  return 0;
}