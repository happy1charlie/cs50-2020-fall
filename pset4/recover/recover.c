#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define bufferSize 512

int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;

    if (argc != 2) {
        return 1;
    }

    // why i dont need to declare input here? but i need to declare output.
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        return 1;
    }

    FILE* output = NULL;
    BYTE buffer[bufferSize];
    int jpegFound = 0;
    int fileCounter = 0;

    while (fread(buffer, bufferSize, 1, input) == 1) {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
           if (jpegFound == 0) {
                jpegFound = 1;
            } else {
                fclose(output);
            }

        char fileName [8];
        sprintf(fileName, "%03i.jpg", fileCounter);

        output = fopen(fileName, "w");
        fileCounter++;
        }

        if (jpegFound == 1) {
            fwrite (buffer, bufferSize, 1, output);
        }
    }

    fclose(input);
    fclose(output);

    return 0;
}

// find out how to use sprintf