#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char str[50];
  int i, consonantCount = 0, vowelCount = 0, uppercaseCount = 0, lowercaseCount = 0;

  scanf("%s", str);
  int length = strlen(str);

  printf("Size of input string is %d\n", length);

  for (i = 0; i < length; i++) {
    if (isalpha(str[i])) {
      if (isupper(str[i])) {
        uppercaseCount++;
      } else {
        lowercaseCount++;
      }
      switch (tolower(str[i])) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
          vowelCount++;
          break;
        default:
          consonantCount++;
          break;
      }
    }
  }

  printf("#Consonants: %d\n", consonantCount);
  printf("#Vowels: %d\n", vowelCount);
  printf("#Upper-case letters: %d\n", uppercaseCount);
  printf("#Lower-case letters: %d\n", lowercaseCount);

  // Check if palindrome
  int isPalindrome = 1;
  for (i = 0; i < length / 2; i++) {
    if (tolower(str[i]) != tolower(str[length - i - 1])) {
      isPalindrome = 0;
      break;
    }
  }

  if (isPalindrome) {
    printf("Is a palindrome string: Yes\n");
  } else {
    printf("Is a palindrome string: No\n");
  }

  return 0;
}