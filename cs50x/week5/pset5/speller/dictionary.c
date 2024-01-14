// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// to track how many words in
int dict_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // return true if word is in dict, else return false

    // first, we get the hash value of the word
    int hash_value = hash(word);

    // then we access the linked list at the hashed value of the array in the hash table
    node *n = table[hash_value];

    // then we check if the word is in the linked list by traversing the linked list
    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }
        n = n->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open the dictionary file
    FILE *dictionary_ptr = fopen(dictionary, "r");
    char wordBuffer[LENGTH + 1];
    node *new_node = NULL;

    if (dictionary_ptr == NULL)
    {
        printf("Error opening and reading this file %s.\n", dictionary);
        return false;
    }
    // Read each word in the file

    // while there are still words
    while (fscanf(dictionary_ptr, "%s", wordBuffer) != EOF)
    {
        new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Unable to malloc node\n");
            return false;
        }
        // read strings from file and copy word into node using strcpy
        // strcpy is used as such - strcpy(destination,source)
        strcpy(new_node->word, wordBuffer);

        // hash word to get hash value
        int hash_value = hash(wordBuffer);

        // Add each word to the hash table at the indexed location
        new_node->next = table[hash_value];
        table[hash_value] = new_node;
        dict_count++;
    }

    // Close the dictionary file
    fclose(dictionary_ptr);

    // Increase dict count  by 1
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dict_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // iterate over hash table and free nodes in each linked list
    for (int i = 0; i < N; i++)
    {
        node *n = table[i];
        while (n != NULL)
        {
            // make tmp the current cursor
            node *tmp = n;
            n = n->next;
            free(tmp);
        }
        // check if all nodes have been freed and return true if so
        if (n == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
