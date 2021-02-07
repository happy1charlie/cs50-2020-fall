#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>

void swap(int firstIndex, int secondIndex, int array []);
void bubbleSort(int array[], int length);
int binarySearch(int array [], int target, int startIndex, int endIndex);

int main(void) {
    int inputArray[10] = { 0 };
    int arrayLength = 10;
    int target = 50;

    printf("target: %d\n", target);

    printf("input array\n");
    for (int i = 0; i < arrayLength; i++) {
        inputArray[i] = (rand() % 100) + 1 ;
        printf("%d ", inputArray[i]);
    }

    printf("\n");

    bubbleSort(inputArray, arrayLength);
    for (int i = 0; i < arrayLength; i ++) {
        printf("%d\n", inputArray[i]);
    }

    int answer = binarySearch(inputArray, target, 0, arrayLength - 1);
    printf("Search:%d\n", answer);

}

int binarySearch(int array [], int target, int startIndex, int endIndex){

    printf("startIndex:%d, endIndex -> %d\n", startIndex, endIndex);
    printf("(startIndex + endIndex) / 2 -> %d\n", (startIndex + endIndex) / 2);

    if (array[(startIndex + endIndex) / 2] == target) {
        return (startIndex + endIndex) / 2;
        printf("final:%d",endIndex / 2 );
    } else if (array[(startIndex + endIndex) / 2] < target) {
        return binarySearch (array, target, (startIndex + endIndex) / 2, endIndex);
    } else if (array[(startIndex + endIndex) / 2] > target) {
        return binarySearch (array, target, startIndex, (startIndex + endIndex) / 2);
    }
    return -1;
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

void swap(int firstIndex, int secondIndex, int array [])
{
  // int * modifiedArray;
  // modifiedArray[firstIndex] = array[secondIndex];
  // modifiedArray[secondIndex] = array[firstIndex];

  int tmp = array[firstIndex];
  array[firstIndex] = array[secondIndex];
  array[secondIndex] = tmp;
}