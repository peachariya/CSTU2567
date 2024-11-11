#include <stdio.h>

int main() {
  int N, i, j, sumRow, sumCol, sumDiag1, sumDiag2, magicNumber;
  int arr[8][8];

  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      scanf("%d", &arr[i][j]);
    }
  }

  // Check if all numbers are unique and in range
  int uniqueNumbers[N * N];
  for (i = 0; i < N * N; i++) {
    uniqueNumbers[i] = 0;
  }
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (arr[i][j] < 1 || arr[i][j] > N * N || uniqueNumbers[arr[i][j] - 1]) {
        printf("This is NOT a magic square!\n");
        return 0;
      }
      uniqueNumbers[arr[i][j] - 1] = 1;
    }
  }

  // Calculate sum of rows, columns, and diagonals
  magicNumber = 0;
  for (i = 0; i < N; i++) {
    sumRow = 0;
    sumCol = 0;
    for (j = 0; j < N; j++) {
      sumRow += arr[i][j];
      sumCol += arr[j][i];
    }
    if (i == 0) {
      magicNumber = sumRow;
    } else if (sumRow != magicNumber || sumCol != magicNumber) {
      printf("This is NOT a magic square!\n");
      return 0;
    }
  }

  sumDiag1 = 0;
  sumDiag2 = 0;
  for (i = 0; i < N; i++) {
    sumDiag1 += arr[i][i];
    sumDiag2 += arr[i][N - i - 1];
  }
  if (sumDiag1 != magicNumber || sumDiag2 != magicNumber) {
    printf("This is NOT a magic square!\n");
    return 0;
  }

  printf("This is a magic square!\n");
  return 0;
}