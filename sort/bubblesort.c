#include<stdio.h>
#include <stdlib.h>
#include<cs50.h>

void swap(int firstIndex, int secondIndex, int array []);
void bubbleSort (int array[], int length);

int main(void){
    int inputArray[10] = { 0 };

    printf("input array\n");
    for (int i = 0; i < 10; i++) {
        inputArray[i] = (rand() % 100) + 1 ;
        printf("%d ", inputArray[i]);
    }
    printf("\n");

    bubbleSort(inputArray, 10);

    for (int i = 0; i < 10; i ++) {
        printf("%d\n", inputArray[i]);
    }

}

void bubbleSort (int array[], int length)
{

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1; j++) {
            // printf("before: \n");
            // printf("array[%d]: %d\n", i, array[i]);
            // printf("array[%d]: %d\n", i + 1, array[i + 1]);

            if (array[j] > array[j + 1]){
                swap(j, j + 1, array);
            }

            // printf("after: \n");
            // printf("array[%d]: %d\n", i, array[i]);
            // printf("array[%d]: %d\n", i + 1, array[i + 1]);
        }
    }

}

void swap(int firstIndex, int secondIndex, int array [])
{

  // int * modifiedArray;
  // modifiedArray[firstIndex] = array[secondIndex];
  // modifiedArray[secondIndex] = array[firstIndex];

  int tmp = array[firstIndex];
  array[firstIndex] = array[secondIndex];
  array[secondIndex] = tmp;


}