#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void) {
    string article = get_string("Test article\n");

    int space = 0, exclamation = 0, questionMark = 0, comma = 0, letter = 0;
    int index = 0; // index 比較好

    while (article[index] != '\0') {
        if(article[index] == ' ') {
            space++;
        } else if ((article[index] >= 'A' && article[index] <= 'Z') || (article[index] >= 'a' && article[index] <= 'z')) {
            letter++;
        } else if (article[index] == '!') {
            exclamation++;
        } else if (article[index] == '?') {
            questionMark++;
        } else if (article[index] == '.') {
            comma++;
        }
        index++;
    }

    float sentence = exclamation + questionMark + comma;
    float word = space + 1;

    double L = letter / word * 100;
    double S = sentence / word * 100;

    float answer = (0.0588 * L) - (0.296 * S) - 15.8;

    if (answer > 16) {
        printf("Grade 16+\n");
    } else if (answer < 1) {
        printf("Before Grade 1\n");
    } else {
        printf("Grade %d\n", (int) round(answer));
    }
    return 0;
}