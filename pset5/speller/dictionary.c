// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 210000000;

// Hash table
node *table[N];

unsigned int dictionarySize = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);
    int wordLength = strlen(word);
    char checkVolcabulary[wordLength + 1];

    //printf("%i", index);

    for(int i = 0; i < wordLength + 1; i++) {
        checkVolcabulary[i] = tolower(word[i]);
    }

    node *cursor = table[index];

    while(cursor != NULL) {
        if(strcmp(checkVolcabulary, cursor->word) == 0) {
            return true;
        }else {
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++) {
        hash = (hash << 2) ^ word[i];
    }
    return hash % N;

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{

    FILE *input = fopen(dictionary, "r");
    if (input == NULL) {
        return false;
    }

    char volcabulary[LENGTH + 1];
    while (fscanf(input, "%s", volcabulary) != EOF) {
        int hashNumber = 0;

        fscanf(input, "%s", volcabulary);

        node *newWord = malloc(sizeof(node));
        if (newWord == NULL) {
            //unload();
            fclose(input);
            return false;
        }

        newWord->next = NULL;

        strcpy(newWord->word, volcabulary);
        hashNumber = hash(volcabulary);

        if (table[hashNumber] == NULL) {
            table[hashNumber] = newWord;
        } else {

            while (table[hashNumber]->next != NULL) {
                table[hashNumber]->next->next =
            }
            cursor = newWord;
        }

    dictionarySize++;
    }

    fclose(input);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dictionarySize;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++) {
        node *cursor = table[i];
        node *tmp = NULL;

        while (cursor != NULL) {
            tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
