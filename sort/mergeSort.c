#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>

void swap(int firstIndex, int secondIndex, int array []);
void bubbleSort(int array[], int length);
void mergeSort(int array[], int length);

int main(void) {
    int inputArray[10] = { 0 };
    int arrayLength = 10;
    //int target = 50;

    //printf("target: %d\n", target);

    printf("input array\n");
    for (int i = 0; i < arrayLength; i++) {
        inputArray[i] = (rand() % 100) + 1 ;
        printf("%d ", inputArray[i]);
    }
    printf("\n\n");

    selectionSort(inputArray, arrayLength);

    for (int i = 0; i < arrayLength; i++){
        printf("%d\n", inputArray[i]);
    }
    printf("\n");

}


void bubbleSort (int array[], int length)
{
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1; j++) {
            if (array[j] > array[j + 1]){
                swap(j, j + 1, array);
            }
        }
    }
}

void swap(int firstIndex, int secondIndex, int array []) {
  int tmp = array[firstIndex];
  array[firstIndex] = array[secondIndex];
  array[secondIndex] = tmp;
}

void mergeSort(int array[], int length){

    int midPosition = length / 2;
    for (int i = 0; i < midPosition; i++) {
        array[i]
    }



        mergeSort(array,length)
    }
}