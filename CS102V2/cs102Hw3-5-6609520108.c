#include <stdio.h>

// Read square function
void readSquare(int arr[8][8], int N) {
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
}

// Find magic number function
int findMagicNumber(int arr[8][8], int N) {
  int i, j, sumRow, sumCol, sumDiag1, sumDiag2, magicNumber = 0;

  // Check if all numbers are unique and in range
  int uniqueNumbers[N * N];
  for (i = 0; i < N * N; i++) {
    uniqueNumbers[i] = 0;
  }
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (arr[i][j] < 1 || arr[i][j] > N * N || uniqueNumbers[arr[i][j] - 1]) {
        return -1; // Not a magic square
      }
      uniqueNumbers[arr[i][j] - 1] = 1;
    }
  }

  // Calculate sum of rows, columns, and diagonals
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
      return -1; // Not a magic square
    }
  }

  sumDiag1 = 0;
  sumDiag2 = 0;
  for (i = 0; i < N; i++) {
    sumDiag1 += arr[i][i];
    sumDiag2 += arr[i][N - i - 1];
  }
  if (sumDiag1 != magicNumber || sumDiag2 != magicNumber) {
    return -1; // Not a magic square
  }

  return magicNumber; // Magic square
}

int main(){

    int arr[8][8];
    int N;

    scanf("%d", &N);
    readSquare(arr, N);

    int magicNumber = findMagicNumber(arr, N);

    if (magicNumber == -1) {
        printf("Your square is NOT a magic square.");
    } else {
        printf("Your square is a magic square!! with the magic constant = %d.", magicNumber);
    }

    return 0;
}