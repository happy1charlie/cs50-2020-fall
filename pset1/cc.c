#include <stdio.h>
#include <cs50.h>

int main(void) {

  int inputNumber;

  do
  {
    inputNumber = get_int("How many stair do you want? ");
  }
  while (inputNumber > 8 || inputNumber < 1);

  int i = 0, j = 0;


  for (i = 0; i < inputNumber; i++) {
    int spaceNumber = inputNumber - i;

    for (j = 0; j < spaceNumber; j++) {
      printf(" ");
    }

    for (j = 0; j < i + 1; j++) {
      printf("*");
    }

    printf("\n");
  }



  return 0;
}