#include <stdio.h>

int main() {
  int N, i, j, maxIndex = 0, minIndex = 0;
  float *numbers, sum = 0, average;
  
  scanf("%d", &N);
  numbers = (float *) malloc(N * sizeof(float));

  for (i = 0; i < N; i++) {
    scanf("%f", &numbers[i]);
  }

  // ค่าสูงสุด ตำแหน่งของค่าสูงสุด ค่าต่ำสุด ตำแหน่งของค่าต่ำสุด และค่าเฉลี่ย
  float max = *numbers;
  float min = *numbers;
  for (i = 1; i < N; i++) {
    if (numbers[i] > max) {
      max = numbers[i];
      maxIndex = i;
    }
    if (numbers[i] < min) {
      min = numbers[i];
      minIndex = i;
    }
    sum += numbers[i];
  }
  average = sum / N;

  printf("Maximum value: %.2f\n", max);
  printf("Minimum value: %.2f\n", min);
  printf("Maximum index: %d\n", maxIndex);
  printf("Minimum index: %d\n", minIndex);
  printf("Average: %.2f\n", average);

  // Reverse order
  printf("Reverse order: ");
  for (i = N - 1; i >= 0; i--) {
    printf("%.2f ", numbers[i]);
  }
  printf("\n");

  // พิมพ์ค่าทุกค่าที่มีค่ามากกว่าค่าเฉลี่ย 
  printf("Above average list: ");
  for (i = 0; i < N; i++) {
    if (numbers[i] > average) {
      printf("%.2f ", numbers[i]);
    }
  }
  printf("\n");

  // พิมพ์ทุกคู่อันดับของตัวเลขทุกตัวที่สร้างจากตัวเลขในอาเรย์ที่เป็นค่าติดลบทั้งคู่
  printf("Negative coordinates: ");
  for (i = 0; i < N; i++) {
    for (j = i + 1; j < N; j++) {
      if (numbers[i] < 0 && numbers[j] < 0) {
        printf("(%.2f, %.2f), ", numbers[i], numbers[j]);
      }
    }
  }
  printf("\n");

  free(numbers);
  return 0;
}