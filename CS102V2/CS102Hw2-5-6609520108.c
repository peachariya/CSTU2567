#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
  if (num <= 1) return false;
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) return false;
  }
  return true;
}

int main() {
  int num;

  do {
    printf("Please enter an integer <between 2 to 9999999> : ");
    scanf("%d", &num);
    if (num <= 1 || num > 9999999) {
      printf("%d is not between 2 to 9999999, please re-enter.\n", num);
    }
  } while (num <= 1 || num > 9999999);

  if (isPrime(num)) {
    printf("%d is a prime number.\n", num);
  } else {
    printf("%d is not a prime number.\n", num);
  }

  return 0;
}