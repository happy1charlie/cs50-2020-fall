#include <stdio.h>
#include <cs50.h>

void swap(int firstIndex, int secondIndex, int array []);

int main(void) {

  int array[] = {1, 2, 3, 4};
  int length = 4;
  int firstIndex = 0;
  int secondIndex = 2;

  swap(firstIndex, secondIndex, array);

  printf("array\n");
  for (int i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}

void swap(int firstIndex, int secondIndex, int array []) {

  // int * modifiedArray;
  // modifiedArray[firstIndex] = array[secondIndex];
  // modifiedArray[secondIndex] = array[firstIndex];

  int tmp = array[firstIndex];
  array[firstIndex] = array[secondIndex];
  array[secondIndex] = tmp;
}