#include<stdio.h>
#include<cs50.h>

int main(void)
{

    long long int inputNumber;

    while(true) {
        inputNumber = get_int("How many level in this diamond? \n");
        if (inputNumber > 100 || inputNumber < 1) {

        } else if (inputNumber % 2 == 0) {

        } else {
            break;
        }
    }

    // 1 == 1 -> 1
    // 0 == 1 -> 0
    // check 1 -> 1

    int check = inputNumber % 2;
    int i, j, k;

    for(i = 0; i < inputNumber /2 ; i++) {
            int space = inputNumber / 2 - i;
            for(j = 0; j < space; j++)
            {
                printf(" ");
            }

            int hash = i * 2 + 1;
            for(k = 0; k < hash; k++)
            {
                printf("#");
            }

            printf("\n");
        }

        int o;
        for (o = 0; o < inputNumber; o++)
        {
            printf("#");
        }

        printf("\n");

        int l, m, n;

        for (l = 0; l < inputNumber / 2; l++)
        {
            int numOfspace = l + 1;
            for(m = 0; m < numOfspace; m++)
            {
                printf(" ");
            }

            int numOfhash = inputNumber - 2 * l - 2;
            for(n = 0; n < numOfhash; n++)
            {
                printf("#");
            }

            printf("\n");
        }

        return 0;

}