// Implements a dictionary's functionality

#include <stdbool.h>
#include <ctype.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
// 26 buckets for 26 alphabets
const unsigned int N = 26;
int totalWords = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node *tmp = table[hash(word)];
    
    if (strcasecmp(tmp->word, word) == 0)
    {
        return true;
    }
    
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }
    }
    
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    return (int) tolower(word[0]) - 97;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char *dictWord = malloc(sizeof(LENGTH + 1));
    
    // read each individual word in
    while (fscanf(file, "%s", dictWord) != EOF)
    {
        // allocate memory for a node and store a pointer n 
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        
        // copy from dictWord into the n's word
        strcpy(n->word, dictWord);
        
        // increment size of hash table
        totalWords ++;
        
        // set n's next to beginning of hash table's linked list
        n->next = table[hash(dictWord)];
        
        // set pointer to hash table linked list to n
        table[hash(dictWord)] = n;
    }
    
    fclose(file);   
    free(dictWord);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return totalWords;
}

// Unloads dictionary from memory, returning true if successful else false
// freeing memory is important to get rid of memory leaks, which slows down 
// our computer
bool unload(void)
{
    // initialize two pointers
    node *tmp;
    node *cursor;
    // iterate over all 26 linked lists
    for (int i = 0; i < N; i ++)
    {
        // if head of linked list is null, continue with next iteration 
        if (table[i] == NULL)
        {
            continue;
        }
        
        // set both pointers to head of linked list
        cursor = table[i];
        tmp = cursor;
        
        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    
    return true;
}
