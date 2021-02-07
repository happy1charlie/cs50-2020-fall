#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    long long cardNumber;
    do
    {
        cardNumber = get_long("Please enter your credit card number.\n");
    }
    while (cardNumber < 0);

    int i = 0, check = 0;
    int oddDigt = 0, oddPDigt = 0, oddPDigt2 = 0, oddSum = 0, final = 0;
    int evenSum = 0;

    long card = cardNumber;

    while (card > 0.9){
        check = card % 10;
        card /= 10;
        i++;

        // Take the second to last digit
        if (i % 2 == 0){
            oddDigt = check * 2;
            oddPDigt = oddDigt % 10;
            oddPDigt2 = oddDigt / 10;
            oddSum = oddSum + oddPDigt + oddPDigt2;
        } else{
            evenSum += check;
        }
        final = oddSum + evenSum;
    }

    if(final % 10 == 0){
        if (cardNumber >= 340000000000000 && cardNumber < 350000000000000){
            printf("AMEX\n");
        }
        else if (cardNumber >= 370000000000000 && cardNumber < 380000000000000){
            printf("AMEX\n");
        }
        else if (cardNumber >= 5100000000000000 && cardNumber < 5600000000000000){
            printf("MASTERCARD\n");
        }
        else if (cardNumber >= 4000000000000 && cardNumber < 5000000000000){
            printf("VISA\n");
        }
        else if (cardNumber >= 4000000000000000 && cardNumber < 5000000000000000){
            printf("VISA\n");
        }
        else{
            printf("INVALID\n");
        }
    }
    else{
        printf("INVALID\n");
    }
    return 0;
}
