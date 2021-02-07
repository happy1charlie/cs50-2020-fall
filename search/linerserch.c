#include<stdio.h>

int linerSerch(int target, int length, int array []);

int main(void){

    int target = 9;
    int length = 8;
    int array[8] = {0, 1, 2, 3, 4, 5, 7, 9};

    int answer = linerSerch(target, length, array);
    printf("%i\n", answer);
}

int linerSerch(int target, int length, int array []) {

    for (int i = 0; i < length; i++) {
        if (array[i] == target) {
            return i;
        }
    }

    return -1;
}