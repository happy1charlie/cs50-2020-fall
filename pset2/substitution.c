#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    int index = 0;
    int isSeenArray[26] = { 0 };

    for (int i = 0; i < 26; i++) {
        isSeenArray[i] = 0;
    }

    if (argc != 2) {
        printf("Usage: ./substitution key");
        return 1;
    }

    while (argv[1][index] != '\0') {
        int letter = (int) argv[1][index];
        int upperCase = letter >= (int) 'A' && letter <= (int) 'Z';
        int lowerCase = letter >= (int) 'a' && letter <= (int) 'z';

        if (!(lowerCase || upperCase)) {
            printf("There sould be all English character\n");
            return 1;
        } else {
            char loweredChar = tolower(argv[1][index]);
            int charIndex = loweredChar - (int) 'a';

            if (isSeenArray[charIndex] == 1) {
                printf("Cannot repeat\n");
                return 1;
            } else {
                isSeenArray[charIndex] = 1;
            }
            index++;
        }
    }

    if (index != 26){
        printf("There sould be 26 character\n");
        return 1;
    }

    int keyArray[26] = { 0 };

    for (index = 0; index < 26; index++) {
        char loweredKey = tolower(argv[1][index]);
        int relativePosition = (int)loweredKey;
        keyArray[index] = relativePosition;
        //printf("lowkey:%d  relatP:%d index:%d \n",loweredKey, relativePosition, index);
    }

    string plaintext = get_string("plaintext:\n");

    char ciphertext[999] = "";

   // printf("plaintext %s\n", plaintext);

    int plaintextIndex = 0;

    while(plaintext[++plaintextIndex] != '\0') {}
   // printf("plaintext %i\n", plaintextIndex);

    for (int j = 0; j < plaintextIndex; j++) {
        if (islower(plaintext[j])){
            ciphertext[j] = keyArray[(int)plaintext[j] - 'a'];
        } else if (isupper(plaintext[j])) {
            ciphertext[j] = keyArray[(int)plaintext[j] - 'A'] - 32;
        } else {
            ciphertext[j] = plaintext[j];
        }
        //printf("j: %d ciphertext: %c\n", j, ciphertext[j]);
    }
    printf("ciphertext: ");

    for (int k = 0; k < plaintextIndex; k++) {
      printf("%c", ciphertext[k]);
    }
    printf("\n");

    return 0;
}