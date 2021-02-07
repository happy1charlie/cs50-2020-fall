#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int inputNumber;
    
    
    //   1.  N -> 0 2 * 0 + 1
    //  123 N ->1 
    // 12345

    do
    {
        inputNumber = get_int("How many stair do you want? ");
    }
    while (inputNumber > 8 || inputNumber < 1);

    int i = 0, j = 0, k = 0;
    for(i = 0; i < inputNumber; i++)
    {
        int spaceNumber = inputNumber - i;

        for(j = 1; j < spaceNumber; j++)
        {
            printf(" ");
        }

        int numberOfStair = 2 * i + 1;

        for(k = 0; k < numberOfStair; k++)
        {
            printf("#");
        }


        printf("\n");
    }

    return 0;
}